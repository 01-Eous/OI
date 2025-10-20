#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,m,x,y;
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
void init(int n = 2e5)
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
int calc(int n,int m){return c(n + m - 1,n - 1);}
signed main()
{
    init(); 
    scanf("%lld%lld%lld%lld",&m,&n,&x,&y);
    int ans = 0;
    if (x <= n && n < y)
        for (int i = 1; i <= m; i++)
            ans = (ans + calc(i,x - 1) * calc(m - i + 1,n - x) % mod * calc(m - i + 1,y - n - 1) % mod * calc(i,n * 2 - y) % mod) % mod;
    else
        ans = calc(m,n - (x - y)) * calc(m,n) % mod;
    printf("%lld",ans);
    return 0;
}