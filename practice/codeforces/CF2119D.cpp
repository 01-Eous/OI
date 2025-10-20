#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
int n,mod;
void solve()
{
    scanf("%lld%lld",&n,&mod);
    vector<vector<int>> dp(n + 5,vector<int>(n + 5,0));
    dp[n][0] = 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= n - i; j++)
        {
            add(dp[i - 1][j],dp[i][j]);
            add(dp[i - 1][j + 1],dp[i][j] * i % mod * (n - i - j + 1));
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        add(ans,dp[0][i]);
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