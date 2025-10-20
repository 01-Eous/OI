#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n,m,v;
int fac[maxn],inv[maxn];
inline int binpow(int x,int y)
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
inline void init(int up = 1e6)
{
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[up] = binpow(fac[up],mod - 2);
    for (int i = up - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline int c(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
inline void solve()
{
    cin >> n >> m >> v;
    int tmp1,tmp2,tmp3,ans = 0;
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            tmp1 = binpow(k,i) * binpow(v,n - i) % mod;
            tmp2 = (tmp1 - binpow(v - k + 1,n - i) + mod) % mod;
            tmp3 = (binpow(tmp2,m) - binpow(tmp1,m) + mod) % mod;
            ans = (ans + (i & 1 ? -1 : 1) * c(n,i) * tmp3 % mod + mod) % mod;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}