#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
int n,m;
int siz[2005],dp[2005][2005];
vector<pii> g[2005];
void dfs(int u,int fa)
{
    siz[u] = 1;
    for (auto [v,w] : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        siz[u] += siz[v];
        for (int j = max(siz[u],m); ~j; j--)
            for (int k = max(0LL,j - siz[u] + siz[v]); k <= min(j,siz[v]); k++)
                dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k] + k * (m - k) * w + (siz[v] - k) * (n - m - siz[v] + k) * w);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v,w; i < n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    cout << dp[1][m];
    return 0;
}