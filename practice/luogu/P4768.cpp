#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 4e5 + 5;
int n,m,q,k,s,cnt;
int dis[maxn],vis[maxn];
int val[maxn],fa[maxn],anc[maxn][25],ans[maxn];
struct edge{int u,v,w;}e[maxn];
struct graph
{
    int head[maxn],idx;
    struct edge{int v,w,nxt;}e[maxn << 1];
    void adde(int u,int v,int w)
    {
        e[++idx] = {v,w,head[u]};
        head[u] = idx;
    }
}g1,g2;//g1 是原图，g2 是重构树。
void clear()
{
    g1.idx = g2.idx = 0;
    memset(anc,0,sizeof anc);
    memset(ans,0x3f,sizeof ans);
    memset(g1.head,0,sizeof g1.head);
    memset(g2.head,0,sizeof g2.head);
}
void read(int &x)
{
    char f = 1,ch = getchar();x = 0;
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
bool cmp(const edge &x,const edge &y){return x.w > y.w;}
void dij(int st = 1)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[st] = 0;
    q.push({dis[st],st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = g1.head[u]; i; i = g1.e[i].nxt)
        {
            int v = g1.e[i].v,w = g1.e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void kruskal()
{
    sort(e + 1,e + m + 1,cmp);
    iota(fa + 1,fa + n + 1,1);
    cnt = n;
    for (int i = 1; i <= m; i++)
    {
        auto [u,v,w] = e[i];
        u = find(u),v = find(v);
        if (u == v)
            continue;
        val[++cnt] = w;
        fa[u] = fa[v] = fa[cnt] = cnt;
        g2.adde(cnt,u,0);
        g2.adde(cnt,v,0);
    }
}
void dfs(int u)
{
    ans[u] = dis[u];
    for (int i = g2.head[u]; i; i = g2.e[i].nxt)
    {
        int v = g2.e[i].v;
        anc[v][0] = u;
        dfs(v);
        ans[u] = min(ans[u],ans[v]);
    }
}
void solve()
{
    clear();
    read(n),read(m);
    int u,v,l,a,lst = 0;
    for (int i = 1; i <= m; i++)
    {
        read(u),read(v),read(l),read(a);
        g1.adde(u,v,l);
        g1.adde(v,u,l);
        e[i] = {u,v,a};
    }
    dij();
    kruskal();
    dfs(cnt);
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= cnt; u++)
            anc[u][i] = anc[anc[u][i - 1]][i - 1];
    read(q),read(k),read(s);
    while (q--)
    {
        read(v),read(a);
        v = (v + k * lst - 1) % n + 1;
        a = (a + k * lst) % (s + 1);
        for (int i = 20; i >= 0; i--)
            if (anc[v][i] && val[anc[v][i]] > a)
                v = anc[v][i];
        printf("%lld\n",lst = ans[v]);
    }
}
signed main()
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}