#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,idx = 1,tim,sc;
bool vis[maxn];
int u[maxn],v[maxn],head[maxn];
int dfn[maxn],low[maxn],bel[maxn],dis[maxn];
stack<int> stk;
vector<int> g[maxn];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1,stk.push(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        sc++;
        int lst = 0;
        while (lst != u)
        {
            lst = stk.top();
            stk.pop();
            vis[lst] = 0;
            bel[lst] = sc;
        }
    }
}
void spfa(int s)
{
    memset(dis,~0x3f,sizeof(int) * (n + 5));
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (dis[v] == ~inf)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    scanf("%d",&n);
    idx = 1,sc = 0;
    memset(dfn,0,sizeof(int) * (n + 5));
    memset(low,0,sizeof(int) * (n + 5));
    memset(bel,0,sizeof(int) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        scanf("%d",u + i),adde(i,++u[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d",v + i),adde(i,++v[i]);
    while (!stk.empty())
        stk.pop();
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            return (void)puts("No");
    for (int i = 1; i <= n; i++)
    {
        if (bel[i] != bel[u[i]])
            g[bel[i]].push_back(bel[u[i]]);
        if (bel[i] != bel[v[i]])
            g[bel[i]].push_back(bel[v[i]]);
    }
    spfa(bel[1]);
    for (int i = 1; i <= sc; i++)
        if (dis[i] == sc)
            return (void)puts("Yes");
    puts("No");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}