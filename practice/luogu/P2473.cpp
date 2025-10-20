#include<bits/extc++.h>
using namespace std;
const int maxn = 1 << 15 | 5;
int m,n;
int a[maxn],s[maxn];
double dp[105][maxn];
signed main()
{
    scanf("%d%d",&m,&n);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",a + i);
        while (scanf("%d",&x),x)
            s[i] |= 1 << (x - 1);
    }
    for (int i = m; i >= 1; i--)
    {
        for (int k = 0; k < (1 << n); k++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((k & s[j]) == s[j])
                    dp[i][k] += max(dp[i + 1][k],dp[i + 1][k | (1 << (j - 1))] + a[j]) / n;
                else
                    dp[i][k] += dp[i + 1][k] / n;
            }
        }
    }
    printf("%.6lf",dp[1][0]);
    return 0;
}