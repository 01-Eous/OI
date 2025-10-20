#include<bits/extc++.h>
using namespace std;
int n,m;
void solve()
{
    cin >> n >> m;
    vector<int>s(n + 5),g(n + 5),dp(n + 5);
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        g[u] = max(g[u],v);
        s[u]++,s[v + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = max(g[i],g[i - 1]);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i],dp[i - 1]);
        dp[g[i]] = max(dp[g[i]],dp[i - 1] + s[i]);
    }
    cout << dp[n] << '\n';
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