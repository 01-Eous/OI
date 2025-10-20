#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,m,idx,rt,ssiz;
bool vis[maxn];
int head[maxn],buc[maxn];
int siz[maxn],wei[maxn],ans[maxn];
stack<int> stk;
vector<int> son;
vector<pii> q[maxn],vec;
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int fa)
{
    wei[u] = 0,siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int fa,int dis)
{
    vec.push_back({u,dis});
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs2(v,u,dis + 1);
}
void calc(int u)
{
    for (auto v : son)
    {
        if (vis[v])
            continue;
        vector<pii>{}.swap(vec);
        dfs2(v,u,1);
        for (auto [x,dis] : vec)
            for (auto [k,id] : q[x])
                if (dis <= k)
                    ans[id] += buc[k - dis];
        for (auto [x,dis] : vec)
            stk.push(dis),buc[dis]++;
    }
    for (auto [k,id] : q[u])
        ans[id] += buc[0] * buc[k];
    while (!stk.empty())
    {
        buc[stk.top()] = 0;
        stk.pop();
    }
}
void dfs(int u)
{
    vis[u] = 1,son.clear();
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; !vis[v])
            son.push_back(v);
    stk.push(0),buc[0]++;
    calc(u);
    reverse(son.begin(),son.end());
    calc(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        rt = 0,ssiz = siz[v];
        dfs1(v,u),dfs(rt);
    }
}
void solve()
{
    scanf("%d%d",&n,&m),idx = 0;
    memset(ans,0,sizeof(int) * (m + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        q[i].clear();
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v),adde(v,u);
    }
    for (int i = 1,x,k; i <= m; i++)
    {
        scanf("%d%d",&x,&k);
        q[x].push_back({k,i});
    }
    wei[0] = inf;
    rt = 0,ssiz = n;
    dfs1(1,0),dfs(rt);
    for (int i = 1; i <= m; i++)
        printf("%d\n",ans[i]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}