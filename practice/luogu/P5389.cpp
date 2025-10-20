#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 998244353;
int n;
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
signed main()
{
    scanf("%lld",&n);
    n %= mod;
    if (!n)
        printf("%lld",inv(2));
    else
        printf("%lld",(1 - 3 * inv(n) % mod * inv(n + 2) % mod + mod) % mod * inv(2) % mod);
    return 0;
}