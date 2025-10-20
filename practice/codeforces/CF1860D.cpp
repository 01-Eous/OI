#include<bits/extc++.h>
using namespace std;
int n,py = 5005,cnt0;
char s[105];
int a[105],dp[105][105 * 105];
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i] - '0';
        cnt0 += s[i] == '0';
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][py] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            for (int k = -py; k <= py; k++)
            {
                if (j && k - cnt0 + ((i - j) << 1) + py >= 0)
                    dp[j][k + py] = min(dp[j][k + py] + a[i],dp[j - 1][k - cnt0 + ((i - j) << 1) + py] + (!a[i]));
                else
                    dp[j][k + py] = dp[j][k + py] + a[i];
            }
        }
    }
    printf("%d",dp[n - cnt0][py] >= n ? -1 : (dp[n - cnt0][py] >> 1));
    return 0;
}