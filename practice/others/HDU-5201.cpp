#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,m;// n 个猴子分 m 个桃子
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
void init(int n = 1e6)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
// n 个里面取 m 个的方案数
int c(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
// n 个猴子不加限制取 m 个桃子的方案数
int calc(int n,int m){return c(n + m - 1,n - 1);}
void solve()
{
    scanf("%lld%lld",&n,&m);
    if (n == 1 || m == 1)
        return (void)puts("1");
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= (n - i + m - 2) / (m - 1))
            continue;
        for (int j = 0; n - (j + 1) * i >= 0; j++)
            ans = (ans + (j & 1 ? -1 : 1) * c(m - 1,j) * calc(m - 1,n - (j + 1) * i) % mod + mod) % mod;
    }
    printf("%lld\n",ans);
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