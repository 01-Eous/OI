#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
int n,t,q;
int fac[maxn],inv[maxn];
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
void init(int n = 1e7)
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
    scanf("%lld%lld%lld",&n,&t,&q);
    int x,ans;
    while (q--)
    {
        scanf("%lld",&x);
        ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + c(i * t,x)) % mod;
        printf("%lld\n",ans);
    }
    return 0;
}