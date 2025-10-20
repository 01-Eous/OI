#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
int dp[5005][5005];
int a[5005],suf[5005];
signed main()
{
    scanf("%lld",&n);
    assert(n <= 5000);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1],a[i]);
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    // dp[i][j] 表示吃完了前 i 列，共吃了 j 次底下的。
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= n; j++)
            dp[i][j] = dp[i - 1][0] + suf[i] * j;
        dp[i][0] = dp[i - 1][0] + a[i];
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i][j],min(dp[i - 1][j] + max(0LL,a[i] - j),dp[i][j - 1] + suf[i]));
    }
    printf("%lld",*min_element(dp[n],dp[n] + a[n] + 1));
    return 0;
}