#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 666013;
int n,m;
int dp[505][505];
int a[505],fac[505];
void init(int n = 500)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> m;
    n = (n + 1) >> 1;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= a[i]; j--)
            for (int k = m; k >= 1; k--)    
                dp[j][k] = (dp[j][k] + dp[j - a[i]][k - 1]) % mod;
    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans = (ans + dp[n][j] * fac[j] % mod * fac[m - j] % mod) % mod;
    cout << ans;
    return 0;
}