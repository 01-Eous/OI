#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int w[20],dp[20][1 << 18 | 5];
signed main()
{
    scanf("%d%d",&n,&m);
    memset(dp,0x3f,sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",w + i);
        dp[1][1 << (i - 1)] = w[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int k = 0; k < (1 << n); k++)
        {
            if (dp[i][k] == inf)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (k & (1 << (j - 1)))
                    continue;
                if (dp[i][k] + w[j] <= m)
                    dp[i][k | (1 << (j - 1))] = min(dp[i][k | (1 << (j - 1))],dp[i][k] + w[j]);
                else
                    dp[i + 1][k | (1 << (j - 1))] = min(dp[i + 1][k | (1 << (j - 1))],w[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i][(1 << n) - 1] <= m)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}