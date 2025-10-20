#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    vector<vector<int>>dp(n + 5,vector<int>(2,0));
    dp[1][0] = 1;
    dp[1][1] = a[1] == 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        if (a[i] > i)
            continue;
        if (a[i] == a[i - 1])
            dp[i][1] = dp[i - 1][1];
        if (a[i] == a[i - 2] + 1)
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
    }
    printf("%lld\n",(dp[n][0] + dp[n][1]) % mod);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}