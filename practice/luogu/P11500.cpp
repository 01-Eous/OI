#include<bits/extc++.h>
#define add(x,y) (x = (x + y) % mod)
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
int n,m;
int dp[5005][5005][2],sum[5005][5005][2];
signed main()
{
    scanf("%d%d",&n,&m);
    if (n == m)
        return printf("1"),0;
    dp[m][m][0] = dp[m][m][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum[m][i][0] = ((ll)sum[m][i - 1][0] + dp[m][i][0]) % mod;
        sum[m][i][1] = ((ll)sum[m][i - 1][0] + dp[m][i][1]) % mod;
    }
    for (int i = m + 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j][0] = sum[i - j][j - 1][1];
            dp[i][j][1] = ((ll)sum[i - j][i - 1][0] - sum[i - j][j][0] + mod) % mod;
        }
        for (int j = 1; j <= n; j++)
        {
            sum[i][j][0] = ((ll)sum[i][j - 1][0] + dp[i][j][0]) % mod;
            sum[i][j][1] = ((ll)sum[i][j - 1][1] + dp[i][j][1]) % mod;
        }
    }
    printf("%lld",((ll)sum[n][n][0] + sum[n][n][1]) % mod);
    return 0;
}