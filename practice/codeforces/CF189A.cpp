#include<bits/extc++.h>
using namespace std;
int n,a,b,c;
signed main()
{
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 5,-1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i >= a && ~dp[i - a])
            dp[i] = max(dp[i],dp[i - a] + 1);
        if (i >= b && ~dp[i - b])
            dp[i] = max(dp[i],dp[i - b] + 1);
        if (i >= c && ~dp[i - c])
            dp[i] = max(dp[i],dp[i - c] + 1);
    }
    cout << dp[n];
    return 0;
}