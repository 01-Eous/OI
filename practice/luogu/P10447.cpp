#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1 << 20 | 5;
int n;
int g[25][25],dp[maxn][25];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld",&g[i][j]);
    memset(dp,0x3f,sizeof dp);
    dp[1][1] = 0;
    for (int k = 0; k < 1 << n; k++)
        for (int i = 1; i <= n; i++)
            if (!(k & (1 << (i - 1))))
                for (int j = 1; j <= n; j++)
                    if (k & (1 << (j - 1)))
                        dp[k | (1 << (i - 1))][i] = min(dp[k | (1 << (i - 1))][i],dp[k][j] + g[j][i]);
    printf("%lld",dp[(1 << n) - 1][n]);
    return 0;
}