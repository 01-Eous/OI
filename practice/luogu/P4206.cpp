#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m,idx,s,t;
bool vis[1005];
double dp[1005][1005];
int head[1005],deg[1005];
int dis[1005][1005],nxt[1005][1005];
struct{int v,nxt;}e[2005];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dij(int *dis,int s)
{
    memset(vis,0,sizeof(bool) * (n + 5));
    memset(dis,0x3f,sizeof(int) * (n + 5));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dis[s] = 0;
    q.push({dis[s],s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push({dis[v],v});
            }
        }
    }
}
double dfs(int u,int w)
{
    if (u == w)
        return 0;
    if (dp[u][w])
        return dp[u][w];
    int fi = nxt[u][w],se = nxt[fi][w];
    if (fi == w || se == w)
        return 1;
    dp[u][w] = 1;
    for (int i = head[w]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        dp[u][w] += dfs(se,v) / (deg[w] + 1);
    }
    dp[u][w] += dfs(se,w) / (deg[w] + 1);
    return dp[u][w];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    int u,v;
    while (m--)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
        deg[u]++,deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        dij(dis[i],i);
    memset(nxt,0x3f,sizeof(nxt));
    for (int i = 1; i <= n; i++)
        for (int k = head[i]; k; k = e[k].nxt)
            for (int j = 1; j <= n; j++)
                if (dis[i][j] == 1 + dis[e[k].v][j])
                    nxt[i][j] = min(nxt[i][j],e[k].v);
    cout << fixed << setprecision(3) << dfs(s,t);
    return 0;
}