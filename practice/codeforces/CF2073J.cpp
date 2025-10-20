#include<bits/extc++.h>
using namespace std;
int n;
int p[505],dp[505][505];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp,0x3f,sizeof dp);
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        p[x] = i;
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + abs(p[i] - p[k + 1]));
        }
    }
    cout << dp[1][n];
    return 0;
}