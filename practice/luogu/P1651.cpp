#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
int dp[2][(int)1e6 + 5];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp,~0x3f,sizeof dp);
    dp[0][(int)5e5] = 0;
    int ans = 0;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        for (int j = 0; j <= 1e6; j++)
        {
            dp[i & 1][j] = max(dp[i & 1][j],dp[(i & 1) ^ 1][j]);
            if (j - x >= 0)
                dp[i & 1][j] = max(dp[i & 1][j],dp[(i & 1) ^ 1][j - x] + x);
            if (j + x <= 1e6)
                dp[i & 1][j] = max(dp[i & 1][j],dp[(i & 1) ^ 1][j + x]);
        }
        ans = max(ans,dp[i & 1][(int)5e5]);
    }
    cout << (ans ? ans : -1);
    return 0;
}