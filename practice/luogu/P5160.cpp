#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 19491001;
int n,m;
int fac[mod],inv[mod];
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
void init(int n = mod - 1)
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
int lucas(int n,int m)
{
    int res = 1;
    while (m)
    {
        res = res * c(n % mod,m % mod) % mod;
        n /= mod,m /= mod;
    }
    return res;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",lucas(n + m,m));
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}