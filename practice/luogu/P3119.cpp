#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
bool vis[maxn];
int u[maxn],v[maxn];
int dis1[maxn],dis2[maxn];
int dfn[maxn],low[maxn],tim;
int siz[maxn],bel[maxn],sc;
stack<int> stk;
vector<int> g[maxn],g1[maxn],g2[maxn];
void dfs(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    stk.push(u);
    for (auto v : g[u])
    {
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
            bel[lst] = sc;
            vis[lst] = 0;
            siz[sc]++;
        }
    }
}
void spfa(int st,int dis[],vector<int> g[])
{
    queue<int> q;
    dis[st] = siz[st];
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto v : g[u])
        {
            if (dis[v] < dis[u] + siz[v])
            {
                dis[v] = dis[u] + siz[v];
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= m; i++)
    {
        if (bel[u[i]] == bel[v[i]])
            continue;
        g1[bel[u[i]]].push_back(bel[v[i]]);
        g2[bel[v[i]]].push_back(bel[u[i]]);
    }
    spfa(bel[1],dis1,g1);
    spfa(bel[1],dis2,g2);
    int ans = siz[bel[1]];
    for (int u = 1; u <= sc; u++)
    {
        if (vis[u] || !dis1[u])
            continue;
        vis[u] = 1;
        for (auto v : g2[u])
            if (dis2[v])
                ans = max(ans,dis1[u] + dis2[v] - siz[bel[1]]);
    }
    cout << ans;
    return 0;
}