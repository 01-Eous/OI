#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
const int maxn = 1e5 + 5;
int n,m,q,idx;
bool vis[maxn];
int head[maxn];
ll dis[maxn],add[maxn];
vector<int> b[maxn];
struct edge{int v,w,nxt;}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dij()
{
    memset(dis,0x3f,sizeof(ll) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    priority_queue<pii,vector<pii>,greater<>> q;
    dis[1] = 0;
    q.push({0,1});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int _ = head[u]; _; _ = e[_].nxt)
        {
            int v = e[_].v;
            if (dis[v] > dis[u] + e[_].w)
            {
                dis[v] = dis[u] + e[_].w;
                q.push({dis[v],v});
            }
        }
    }
}
void bfs(int c)
{
    for (int i = 0; i <= c; i++)
    {
        while (!b[i].empty())
        {
            int u = b[i].back();
            b[i].pop_back();
            if (add[u] < i)
                continue;
            for (int _ = head[u]; _; _ = e[_].nxt)
            {
                int v = e[_].v,w = e[_].w + dis[u] - dis[v];
                if (add[v] > add[u] + w)
                {
                    add[v] = add[u] + w;
                    b[add[v]].push_back(v);
                }
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1,u,v,w; i <= m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w),assert(idx = i);
    }
    dij();
    int op,c;
    while (q--)
    {
        scanf("%d%d",&op,&c);
        if (op == 1)
        {
            printf("%lld\n",dis[c] < inf ? dis[c] : -1LL);
            continue;
        }
        for (int i = 1,x; i <= c; i++)
            scanf("%d",&x),e[x].w++;
        fill(add + 1,add + n + 1,c + 1);
        add[1] = 0,b[0].push_back(1);
        bfs(c);
        for (int i = 1; i <= n; i++)
            dis[i] += add[i];
        for (int i = 1; i <= c; i++)
            b[i].clear();
    }
    return 0;
}