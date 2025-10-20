#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int fac[35],inv[35],dp[maxn][35];
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
void init(int n = 32)
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
    scanf("%lld",&n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 32; j++)
            for (int k = 0; k <= 32 - j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * c(32 - k,j) % mod) % mod;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 32; j++)
            ans = (ans + dp[i][j]) % mod;
    printf("%lld",ans);
    return 0;
}