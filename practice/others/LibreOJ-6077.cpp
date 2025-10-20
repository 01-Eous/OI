#include<bits/extc++.h>
#define int long long
#define calc(n,k) c(n + k - 1,n)
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int mod = 1e9 + 7;
int n,k;
int dp[650][maxn];
int fac[maxm],inv[maxm];
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
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    init();
    scanf("%lld%lld",&n,&k);
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 1; i * (i + 1) >> 1 <= k; i++)
    {
        for (int j = i; j <= k; j++)
        {
            dp[i][j] = (dp[i - 1][j - i] + dp[i][j - i]) % mod;
            if (j >= n + 1)
                dp[i][j] -= dp[i - 1][j - n - 1];
        }   
    }
    for (int i = 0; i * (i + 1) >> 1 <= k; i++)
        for (int j = 0; j <= k; j++)
            ans = (ans + (i & 1 ? -1 : 1) * dp[i][j] * c(k - j + n - 1,k - j) % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}