#include<bits/extc++.h>
using namespace std;
typedef double ld;
int n,t;
ld p,dp[2005][2005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 0; i < t; i++)
    {
        dp[i + 1][n] += dp[i][n];
        for (int j = 0; j < n; j++)
        {
            dp[i + 1][j + 1] += p * dp[i][j];
            dp[i + 1][j] += (1 - p) * dp[i][j];
        }
    }
    ld ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i * dp[t][i];
    cout << fixed << setprecision(6) << ans;
    return 0;
}