#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int a,b,k;
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
void init(int n = 1e5)
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
    int res = 1;
    for (int i = 0; i < m; i++)
        res = res * ((n - i) % mod) % mod;
    return res * inv[m] % mod;
}
void solve()
{
    scanf("%lld%lld%lld",&a,&b,&k);
    int n = k * (a - 1) + 1;
    int m = c(n,a) * k % mod * (b - 1) % mod + 1;
    printf("%lld %lld\n",n % mod,m % mod);
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