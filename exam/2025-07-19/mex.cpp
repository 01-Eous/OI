#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;
int n,x;
int dp[maxn][2];
signed main()
{
    freopen("mex.in","r",stdin);
    freopen("mex.out","w",stdout);
    scanf("%lld",&n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&x);
        dp[x + 1][0] = (dp[x + 1][0] * 2 + dp[x][0]) % mod;
        dp[x + 1][1] = dp[x + 1][1] * 2 % mod;
        if (x)
            dp[x - 1][1] = (dp[x - 1][1] * 2 + dp[x - 1][0]) % mod;
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
        ans = (ans + dp[i][0] + dp[i][1]) % mod;
    printf("%lld",ans);
    return 0;
}