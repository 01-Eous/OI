#include<bits/extc++.h>
#define int long long
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
const int maxn = 1e6 + 5;
int n,mod;
int dp[maxn << 1];
int siz[maxn],fac[maxn],inv[maxn];
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
void init(int n)
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    init(min(n,mod - 1));
    for (int i = 1; i <= n; i++)
        siz[i] = 1;
    for (int i = n; i >= 1; i--)
        siz[i >> 1] += siz[i];
    for (int i = n + 1; i <= (n << 1 | 1); i++)
        dp[i] = 1;
    for (int rt = n; rt >= 1; rt--)
        dp[rt] = lucas(siz[rt] - 1,siz[ls]) * dp[ls] % mod * dp[rs] % mod;
    cout << dp[1];
    return 0;
}