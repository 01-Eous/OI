#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int mod = 1e4 + 7;
int n,m,r;
int fac[mod],inv[mod],dp[15];
pii a[15];
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
void init(int n = mod - 1)
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
int calc(int h,int w)
{
    if ((h + w) % 3)
        return 0;
    int a = (2 * w - h) / 3;
    int b = (2 * h - w) / 3;
    return lucas(a + b,a);
}
void solve(int t)
{
    cin >> n >> m >> r;
    for (int i = 1; i <= r; i++)
        cin >> a[i].first >> a[i].second;
    r++,a[r].first = n,a[r].second = m;
    sort(a + 1,a + r + 1);
    for (int i = 1; i <= r; i++)
    {
        dp[i] = calc(a[i].first - 1,a[i].second - 1);
        for (int j = 1; j < i; j++)
            dp[i] = (dp[i] - dp[j] * calc(a[i].first - a[j].first,a[i].second - a[j].second) % mod + mod) % mod;
    }
    cout << "Case #" << t << ": " << dp[r] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}