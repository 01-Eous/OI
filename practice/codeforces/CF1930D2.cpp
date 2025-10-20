#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,dp[maxn];
char s[maxn];
void solve()
{
    scanf("%lld%s",&n,s + 1);
    int ans = dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            dp[i] = dp[i - min(i,3ll)] + i;
        else
            dp[i] = dp[i - 1];
        ans += dp[i];
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