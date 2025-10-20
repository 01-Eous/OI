#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
double mp[130][130],dp[10][130];
void solve()
{
    m = 1 << n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 0;
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                if ((j >> i) == (k >> i) && (j >> (i - 1)) != (k >> (i - 1)))
                    dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * mp[j][k];
    int pos = 0;
    double _max = 0;
    for (int i = 0; i < m; i++)
    {
        if (_max < dp[n][i])
        {
            _max = dp[n][i];
            pos = i;
        }
    }
    cout << pos + 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n != -1)
    {
        solve();
        cin >> n;        
    }
    return 0;
}