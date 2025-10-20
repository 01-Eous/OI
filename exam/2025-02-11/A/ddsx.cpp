#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 8580287;
int n,a[105],pos[105];
int dp[105][105][105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        fill(dp[i][i] + 1,dp[i][i] + a[i] + 1,1);
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            bool fl = 1;
            for (int v = n; v >= 1; v--)
            {
                dp[l][r][v] = dp[l][r][v + 1];
                if (l <= pos[v] && pos[v] <= r)
                {
                    if (fl)
                    {
                        dp[l][r][v] = 1;
                        fl = 0;
                    }
                    for (int k = pos[v]; k < r; k++)
                    {
                        if (a[k] < v)
                            continue;
                        if (!dp[l][k][v + 1])
                        {
                            dp[l][r][v] = (dp[l][r][v] + dp[k + 1][r][v + 1]) % mod;
                            fl = 0;
                        }
                        else
                            dp[l][r][v] = (dp[l][r][v] + dp[l][k][v + 1] * dp[k + 1][r][v + 1]) % mod;
                    }
                }
            }
        }
    }
    cout << dp[1][n][1];
    return 0;
}