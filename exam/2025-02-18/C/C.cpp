#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n,a,b,p,q;
int dp[maxn],f[maxn];
int fac[maxn],inv[maxn];
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void init(int up = 1e6)
{
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[up] = Inv(fac[up]);
    for (int i = up - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    f[1] = 1;
    for (int i = 2; i <= up; i++)
        f[i] = (f[i - 1] * f[i - 1] + 2) % mod;
}
int C(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    init();
    scanf("%lld%lld%lld",&n,&a,&b);
    p = a * Inv(b) % mod,q = (1 - p + mod) % mod;
    int ans = 0;
    if (p ^ q)
    {
        dp[0] = 1;
        for (int k = 1; k < n; k++)
        {
            dp[k] = dp[k - 1] * (binpow(p,n - k + 1) - binpow(q,n - k + 1) + mod) % mod;
            dp[k] = dp[k] * Inv((binpow(p,k) - binpow(q,k) + mod) % mod) % mod;
            ans = (ans + f[k] * dp[k]) % mod;
        }
    }
    else
    {
        for (int k = 1; k < n; k++)
        {
            dp[k] = C(n,k) * Inv(binpow(2,k * (n - k))) % mod;
            ans = (ans + f[k] * dp[k]) % mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}