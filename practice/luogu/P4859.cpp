#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 9;
int n,k;
int a[2005],b[2005];
int fac[2005],inv[2005];
int dp[2005][2005],g[2005],lst[2005];
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
void init(int n = 2000)
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
    if ((n + k) & 1)
        return puts("0"),0;
    k = (n + k) >> 1;
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i);
    sort(b + 1,b + n + 1);
    for (int i = 1,p = 0; i <= n; i++)
    {
        while (p < n && b[p + 1] < a[i])
            p++;
        lst[i] = p;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * max(0LL,lst[i] - j + 1) % mod) % mod;
    }
    for (int i = 0; i <= n; i++)
        g[i] = dp[n][i] * fac[n - i] % mod;
    int ans = 0;
    for (int i = k; i <= n; i++)
        ans = (ans + ((i - k) & 1 ? -1 : 1) * c(i,k) * g[i] % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}