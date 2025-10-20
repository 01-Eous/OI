#include<bits/extc++.h>
using namespace std;
const int mod = 10000;
int n,m;
int dp[1005][1005];
signed main()
{
    scanf("%d%d",&n,&m);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = max(1,i - j); k <= i; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - (i - k)]) % mod;
    printf("%d",dp[n][m]);
    return 0;
}