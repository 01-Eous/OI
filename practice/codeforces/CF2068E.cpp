#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,m;
int fa[maxn];
int f[maxn],dp[maxn];
int dis[maxn],p[maxn];
vector<int> g[maxn];
vector<array<int,3>> e;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x != y)
        fa[y] = x;
}
void bfs(int st)
{
    queue<int> q;
    dis[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : g[u])
        {
            if (~dis[v])
                continue;
            dis[v] = dis[u] + 1;
            p[v] = u;
            q.push(v);
        }
    }
}
void dij(int st)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,st});
    while (!q.empty())
    {
        auto [tmp,u] = q.top();
        q.pop();
        if (~dp[u])
            continue;
        dp[u] = tmp;
        for (auto v : g[u])
            if (~f[v])
                q.push({max(f[v],dp[u] + 1),v});
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fill(f + 1,f + n + 1,-1);
    fill(p + 1,p + n + 1,-1);
    iota(fa + 1,fa + n + 1,1);
    fill(dp + 1,dp + n + 1,-1);
    fill(dis + 1,dis + n + 1,-1);
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(n);
    for (int u = 1; u <= n; u++)
        for (auto &v : g[u])
            if (v < u && p[u] != v && p[v] != u)
                e.push_back({dis[u] + dis[v] + 1,u,v});
    sort(e.begin(),e.end());
    for (auto [w,u,v] : e)
    {
        u = find(u),v = find(v);
        while (u != v)
        {
            if (dis[u] > dis[v])
            {
                merge(p[u],u);
                f[u] = w - dis[u];
            }
            else
            {
                merge(p[v],v);
                f[v] = w - dis[v];
            }
            u = find(u),v = find(v);
        }
    }
    f[n] = 0;
    dij(n);
    cout << dp[1];
    return 0;
}