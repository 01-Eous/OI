#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,k;
int dp[maxn][15],sum[maxn][15];
signed main()
{
    scanf("%lld%lld",&n,&k);
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = sum[i - 1][j - 1];
            if (i > 2 && i != n)
                dp[i][j] = (dp[i][j] - dp[i - 2][j - 1] + mod) % mod;
            sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
        }
        dp[i][k + 1] = (sum[i - 1][k] + sum[i - 1][k + 1]) % mod;
        if (i > 2 && i != n)
            dp[i][k + 1] = ((dp[i][k + 1] - dp[i - 2][k] - dp[i - 2][k + 1]) % mod + mod) % mod;
        sum[i][k + 1] = (sum[i - 1][k + 1] + dp[i][k + 1]) % mod;
    }
    printf("%lld",(dp[n][k] + dp[n][k + 1]) % mod);
    return 0;
}