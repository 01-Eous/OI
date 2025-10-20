#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
void solve()
{
    cin >> n >> m;
    vector<int>a(n + 5);
    vector<vector<int>>dp(m + 5,vector<int>(n + 5,inf));
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[0][i] = dp[0][i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int _min = inf;
            for (int k = j; k >= max(1ll,j - i); k--)
            {
                _min = min(_min,a[k]);
                dp[i][j] = min(dp[i][j],dp[i - (j - k)][k - 1] + (j - k + 1) * _min);
            }
        }
    }
    cout << dp[m][n] << '\n';
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