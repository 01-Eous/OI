#include<bits/extc++.h>
using namespace std;
int n,m;
int dp[505][105][105][2];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dp,~0x3f,sizeof(dp));
    dp[0][0][0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                if (ch == 'j')
                {
                    dp[i][j][k][0] = max(dp[i - 1][j][k][0],dp[i - 1][j][k][1]);
                    if (j)
                        dp[i][j][k][1] = max(dp[i - 1][j - 1][k][0] + 1,dp[i - 1][j - 1][k][1]);
                }
                else
                {
                    dp[i][j][k][1] = max(dp[i - 1][j][k][0] + 1,dp[i - 1][j][k][1]);
                    if (k)
                        dp[i][j][k][0] = max(dp[i - 1][j][k - 1][0],dp[i - 1][j][k - 1][1]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max({ans,dp[n][i][i][0],dp[n][i][i][1]});
    cout << ans;
    return 0;
}