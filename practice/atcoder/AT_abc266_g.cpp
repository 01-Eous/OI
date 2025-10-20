#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e6 + 6;
const int mod = 998244353;
int r,g,b,k,n;
int fac[maxn],inv[maxn],f[maxn];
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
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n; i > 0; i--)
        inv[i - 1] = inv[i] * i % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> g >> b >> k;
    n = r + g + b,init();
    for (int i = k; i <= min(r,g); i++)
        f[i] = c(n - i,i) * c(n - (i << 1),r - i) % mod * c(n - i - r,g - i) % mod;
    int ans = 0;
    for (int i = k; i <= min(r,g); i++)
        ans = (ans + ((i - k) & 1 ? -1 : 1) * c(i,k) * f[i] % mod + mod) % mod;
    cout << ans;
    return 0;
}