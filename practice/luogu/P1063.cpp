#include<bits/extc++.h>
using namespace std;
int n,a[205];
int dp[205][205];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int len = 2; len <= n + 1; len++)
    {
        for (int i = 1; i + len - 1 <= (n << 1); i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k <= j - 1; k++)
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans,dp[i][i + n]);
    cout << ans;
    return 0;
}