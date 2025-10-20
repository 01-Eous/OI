#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,m,q;
int fac[maxn],inv[maxn],ans[maxn];
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
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    init();
    scanf("%lld%lld%lld",&n,&m,&q);
    ans[0] = c(m,n) * 2 % mod;
    for (int i = 1; i <= m; i++)
    {
        ans[i] = ans[i - 1];
        for (int j = 1; j <= 20; j++)
        {
            int p = (1 << j) - 1;
            ans[i] = (ans[i] + c(i - 1,p - 1) * c(m - i,n - p) % mod * 2 % mod) % mod;
        }
    }
    int res = 0;
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld",&n);
        res ^= i * ans[n];
    }
    printf("%lld",res);
    return 0;
}