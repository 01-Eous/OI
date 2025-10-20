#include<bits/extc++.h>
using namespace std;
typedef long double ld;
int n,r;
int d[250];
ld p[250],pw[250][250],dp[250][250],ans[250];
void solve()
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> d[i];
    for (int i = 1; i <= n; i++)
    {
        pw[i][0] = 1.0;
        for (int j = 1; j <= r; j++)
            pw[i][j] = pw[i][j - 1] * (1.0 - p[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i,r); j++)
        {
            dp[i][j] = dp[i - 1][j] * pw[i][r - j];
            if (j)
                dp[i][j] += dp[i - 1][j - 1] * (1 - pw[i][r - j + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans[i] = 0;
        for (int j = 0; j <= min(i,r); j++)
            ans[i] += dp[i - 1][j] * (1 - pw[i][r - j]);
    }
    ld res = 0;
    for (int i = 1; i <= n; i++)
        res += d[i] * ans[i];
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}