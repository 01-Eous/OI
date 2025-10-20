#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,k;
int fac[maxn],inv[maxn];
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
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    if (k >= n)
        return printf("0"),0;
    init();
    int ans = 0;
    for (int i = 0; i <= n - k; i++)
        ans = (ans + (i & 1 ? -1 : 1) * c(n - k,i) * binpow(n - k - i,n) % mod + mod) % mod;
    ans = ans * c(n,k) % mod;
    if (k)
        ans = ans * 2 % mod;
    printf("%lld",ans);
    return 0;
}