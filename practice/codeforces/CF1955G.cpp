#include<bits/extc++.h>
using namespace std;
int n,m;
int mp[105][105];
bool dp[105][105];
bool chk(int x)
{
    for (int i = 1; i <= n; i++)
        fill(dp[i] + 1,dp[i] + m + 1,0);
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((i != 1 || j != 1) && mp[i][j] % x == 0)
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
    return dp[n][m];
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    vector<int> fac;
    for (int i = 1; i * i < mp[1][1]; i++)
    {
        if (mp[1][1] % i == 0)
        {
            fac.push_back(i);
            fac.push_back(mp[1][1] / i);
        }
    }
    if (sqrt(mp[1][1]) - floor(sqrt(mp[1][1])) <= 1e-9)
        fac.push_back(floor(sqrt(mp[1][1])));
    sort(fac.begin(),fac.end(),greater<>());
    for (auto i : fac)
    {
        if (chk(i))
        {
            cout << i << '\n';
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}