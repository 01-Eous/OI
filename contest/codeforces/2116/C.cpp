#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,g;
int _gcd[5005][5005];
void init(int n = 5000)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            _gcd[i][j] = __gcd(i,j);
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            _gcd[i][j] = _gcd[j][i];
}
void solve()
{
    cin >> n;
    vector<int> a(n + 5);
    vector<vector<int>> dp(n + 5,vector(5005,inf));
    dp[0][0] = g = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g = _gcd[g][a[i]];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += a[i] != g;
    if (cnt != n)
        return cout << cnt << '\n',void();
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= 5000; j++)
        {
            int tmp = _gcd[a[i]][j];
            dp[i][tmp] = min(dp[i][tmp],dp[i - 1][j] + 1);
        }
    }
    cout << dp[n][g] - 1 + n - 1 << '\n';
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