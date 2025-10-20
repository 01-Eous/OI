#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int n,m,k;
int dp[2][maxn];
int fac[maxn << 1],inv[maxn << 1];
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
void init(int n = 4e5)
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
void solve()
{
    cin >> n >> m >> k;
    int res = 0,lim = m;
    if (k == 1)
    {
        res = c(m + n,m);
        goto Hoshino;
    }
    for (int i = 0; i <= m; i++)
        dp[1][i] = i + 1;
    for (int i = 2; i <= n; i++)
    {
        int cur = i & 1,lst = cur ^ 1;
        int nxt = lim / k;
        if (!nxt)
        {
            res = dp[lst][lim];
            break;
        }
        dp[cur][0] = dp[lst][lim];
        for (int j = 1; j <= nxt; j++)
            dp[cur][j] = (dp[cur][j - 1] + dp[lst][lim] - dp[lst][j * k - 1] + mod) % mod;
        lim = nxt;
    }
    if (!res)
        res = dp[n & 1][lim];
    Hoshino:
    cout << (binpow(m + 1,n) - res + mod) % mod << '\n';
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