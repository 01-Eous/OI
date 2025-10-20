#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,x;
int dp[2005];
signed main()
{
    scanf("%lld",&n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&x);
        if (!x)
            continue;
        for (int j = n; j >= x; j--)
            dp[j] = (dp[j] + dp[j - x]) % mod;
    }
    for (int i = n; i >= 1; i--)
    {
        if (dp[i])
        {
            printf("%lld %lld",i,dp[i]);
            return 0;
        }
    }
    return 0;
}