#include<bits/extc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 1e9 + 7;
int n,m;
int sum[maxn],pre[maxn];
int dp[maxn][maxn];
signed main()
{
    cin >> n >> m;
    m -= n;
    for (long i = 1; i <= n; i++)
    {
        for (long j = 0; j <= m; j++)
        {
            pre[j] = (pre[j] + sum[j]) % mod;
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = pre[j];
            if (i + j <= m)
                sum[i + j] = (sum[i + j] + dp[i][j]) % mod;
        }
    }
    cout << dp[n][m];
    return 0;
}