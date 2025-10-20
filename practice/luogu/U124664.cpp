#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int fac[3005],inv[3005];
int pw[(int)1e7 + 5],dp[3005];
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
    fac[0] = pw[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    for (int i = 1; i <= n * n; i++)
        pw[i] = (pw[i - 1] << 1) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    scanf("%lld",&n);
    init(),dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = (dp[i] + (j & 1 ? 1 : -1) * dp[i - j] * pw[j * (i - j)] % mod * c(i,j) % mod + mod) % mod;
    printf("%lld",dp[n]);
    return 0;
}