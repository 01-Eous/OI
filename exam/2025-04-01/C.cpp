#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n,k,ans;
char q[maxn];
int fac[maxn],inv[maxn],f[maxn];
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
void init(int n = 1e6)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int C(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
void solve()
{
    scanf("%lld%lld%s",&n,&k,q);
    k = binpow(2,k);
    int tmp = 1;
    for (int i = n; i >= 0; i--)
    {
        f[i] = ((i & 1 ? -1 : 1) * C(n,i) * tmp % mod + mod) % mod;
        tmp = (tmp * (k - i + 1) % mod + mod) % mod;
    }
    tmp = 1;
    for (int i = 0; i <= n; i++)
        tmp = (tmp * (k - i) % mod + mod) % mod;
    ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + f[i] * tmp % mod) % mod;
    printf("%lld\n",ans * binpow(k,mod - 2) % mod);
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