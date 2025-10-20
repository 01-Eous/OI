#include <bits/extc++.h>
#define int long long
#define sum(l,r) (a[r] - a[l - 1])
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[5005],inv[5005];
int p1[5005],p2[5005];
int pre[5005][5005],suf[5005][5005],dp[5005][5005];
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        p1[i] = n,p2[i] = 1;
        inv[i] = binpow(i,mod - 2);
    }
    dp[1][n] = 1;
    pre[1][n] = suf[1][n] = inv[n - 1];
    for (int len = n - 1; len >= 1; len--)
    {
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
        {
            while (p1[i] > j && sum(i,j) <= sum(j + 1,p1[i]))
                p1[i]--;
            while (p2[j] < i && sum(i,j) < sum(p2[j],i - 1))
                p2[j]++;
            dp[i][j] =
                (suf[i][j + 1] - suf[i][p1[i] + 1] + mod) % mod +
                (pre[i - 1][j] - pre[p2[j] - 1][j] + mod) % mod;
            dp[i][j] %= mod;
            pre[i][j] = (pre[i - 1][j] + dp[i][j] * inv[j - i]) % mod;
            suf[i][j] = (suf[i][j + 1] + dp[i][j] * inv[j - i]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i][i] << '\n';
    return 0;
}