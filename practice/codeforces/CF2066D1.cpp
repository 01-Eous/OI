#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,m,c;
int fac[10005],inv[10005];
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
void init(int up = 1e4)
{
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[up] = binpow(fac[up],mod - 2);
    for (int i = up - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int C(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
void solve()
{
    scanf("%lld%lld%lld",&n,&c,&m);
    vector<int>a(m + 5);
    for (int i = 1; i <= m; i++)
        scanf("%lld",&a[i]);
    vector<vector<int>>dp(n + 5,vector<int>(m + 5,0));
    dp[1][c] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = c; j <= m; j++)
            for (int k = 0; k <= c; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * C(c,k) % mod) % mod;
    printf("%lld\n",dp[n][m]);
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