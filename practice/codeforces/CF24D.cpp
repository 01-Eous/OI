#include<bits/extc++.h>
using namespace std;
int n,m,x,y;
double dp[1005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y;
    for (int i = n - 1; i >= x; i--)
    {
        for (int t = 1; t <= 50; t++)
        {
            if (m == 1)
                dp[i][1] = (dp[i][1] + dp[i + 1][1]) / 2.0 + 1;
            else
            {
                dp[i][1] = (dp[i][1] + dp[i][2] + dp[i + 1][1]) / 3.0 + 1;
                dp[i][m] = (dp[i][m] + dp[i][m - 1] + dp[i + 1][m]) / 3.0 + 1;
                for (int j = 2; j < m; j++)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j]) / 4.0 + 1;
            }
        }
    }
    cout << fixed << setprecision(4) << dp[x][y];
    return 0;
}