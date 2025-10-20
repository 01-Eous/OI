#include<bits/extc++.h>
using namespace std;
int n;
string s,t,ans;
pair<string,string> dp[55][55];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    n = s.length();
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j].first.clear();
                dp[i][j].second.clear();
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = max(dp[i][j],{dp[i - 1][j - 1].first + s[i - 1],dp[i - 1][j - 1].second + t[i - 1]});
            }
        }
        for (int i = 1; i <= n; i++)
            ans = max(ans,dp[i][k].first + dp[i][k].second);
    }
    cout << ans;
    return 0;
}