#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int>a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<bool>>dp(n + 5,vector<bool>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i - 1 >= a[i])
            dp[i][0] = dp[i][0] || dp[i - 1 - a[i]][0] || dp[i - 1 - a[i]][1];
        if (i <= n - a[i])
            dp[i + a[i]][1] = dp[i + a[i]][1] || dp[i - 1][0] || dp[i - 1][1];
    }
    cout << (dp[n][0] || dp[n][1] ? "YES\n" : "NO\n");
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