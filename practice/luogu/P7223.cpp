#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n,p;
int dp[maxn];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&p);
    dp[0] = 1;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        dp[i] = (dp[i - 1] * (1 + binpow(p,x))) % mod;
    }
    printf("%lld",dp[n]);
    return 0;
}