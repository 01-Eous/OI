#include<bits/extc++.h>
using namespace std;
const int maxn = 1.1e7 + 5;
int n;
int dp[maxn << 1];
char ori[maxn],s[maxn << 1];
signed main()
{
    scanf("%s",ori + 1);
    n = strlen(ori + 1) << 1 | 1;
    for (int i = 1; i <= n; i++)
        s[i] = i & 1 ? '{' : ori[i >> 1];
    int r = 0,mid = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= r)
            dp[i] = min(r - i + 1,dp[(mid << 1) - i]);
        while (i - dp[i] >= 1 && i + dp[i] <= n && s[i - dp[i]] == s[i + dp[i]])
            dp[i]++;
        if (i + dp[i] > r)
        {
            mid = i;
            r = i + dp[i] - 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans,dp[i] - 1);
    printf("%d",ans);
    return 0;
}