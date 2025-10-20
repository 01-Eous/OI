#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int fac[5005],inv[5005];
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
void init(int n = 5000)
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
void solve()
{
    scanf("%lld",&n);
    vector<bool> vis(n + 5,0);
    vector<int> a(n + 5),sum(n + 5,0);
    vector<vector<int>> dp(n + 5,vector<int>(n + 5,0));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i - 1];
        if (~a[i])
            vis[a[i]] = 1;
        else
            sum[i]++;
    }
    int min1 = n,min2;
    for (int i = 1; i <= n; i++)
    {
        min2 = n;
        for (int j = n; j >= i; j--)
        {
            int x = sum[j] - sum[i - 1],y = min(min1,min2);
            dp[x][0]++,dp[x][y]--;
            if (~a[j])
                min2 = min(min2,a[j]);
        }
        if (~a[i])
            min1 = min(min1,a[i]);
    }
    for (int i = 0; i <= sum[n]; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    int ans = 0,cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += !vis[i];
        for (int j = cnt; j <= sum[n]; j++)
            ans = (ans + c(j,cnt) * fac[cnt] % mod * fac[sum[n] - cnt] % mod * dp[j][i]) % mod;
    }
    printf("%lld\n",ans);
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