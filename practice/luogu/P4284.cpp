#include<bits/extc++.h>
using namespace std;
typedef double ld;
const int maxn = 5e5 + 5;
const ld eps = 1e-9;
int n;
ld dp[maxn],ans;
vector<pair<int,ld>> g[maxn];
void dfs1(int u,int fa)
{
    for (auto &[v,w] : g[u])
    {
        if (v == fa)
            continue;
        dfs1(v,u);
        ld tmp = dp[v] * w;
        dp[u] = dp[u] + tmp - dp[u] * tmp;
    }
}
void dfs2(int u,int fa)
{
    ans += dp[u];
    for (auto &[v,w] : g[u])
    {
        if (v == fa)
            continue;
        if (fabs(dp[v] * w - 1) < eps)
        {
            dfs2(v,u);
            continue;
        }
        ld tmp = (dp[u] - dp[v] * w) / (1 - dp[v] * w) * w;
        dp[v] = tmp + dp[v] - tmp * dp[v];
        dfs2(v,u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int u,v;
    ld w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        w /= 100.0;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i];
        dp[i] /= 100.0;
    }
    dfs1(1,0);
    dfs2(1,0);
    cout << fixed << setprecision(6) << ans;
    return 0;
}