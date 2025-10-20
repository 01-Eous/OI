#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n,ans;
int dp[maxn];
vector<int>g[maxn];
void dfs(int u,int fa)
{
    dp[u] = 1;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        dp[u] = dp[u] * (dp[v] + 1) % mod;
    }
    ans = (ans + dp[u]) % mod;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 1;
    dfs(1,0);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}