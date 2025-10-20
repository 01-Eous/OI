#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
int dp[maxn];//dp[u] 表示从 u 往下走先手能否赢
vector<int> g[maxn];
void dfs1(int u,int fa)
{
    dp[u] = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs1(v,u);
        dp[u] += !dp[v];
    }
}
void dfs2(int u,int fa)
{
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dp[v] += !(dp[u] - !dp[v]);
        dfs2(v,u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    int x;
    while (m--)
    {
        cin >> x;
        cout << (dp[x] ? "Ron" : "Hermione") << '\n';
    }
    return 0;
}