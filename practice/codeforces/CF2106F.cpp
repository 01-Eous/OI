#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
int dp[maxn][3];
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%1lld",a + i);
        memset(dp[i],0,sizeof(dp[i]));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]) + i - 1;
            dp[i][2] = dp[i - 1][2] + n - i;
        }
        else
            dp[i][1] = dp[i - 1][2] + 1;
        ans = max({ans,dp[i][0],dp[i][1],dp[i][2]});
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}