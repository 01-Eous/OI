#include<bits/extc++.h>
using namespace std;
int n;
int dp[3005][3005];
int a[3005],b[3005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int max1 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i] != b[j])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max1 + 1;
            if (a[i] > b[j])
                max1 = max(max1,dp[i - 1][j]);
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}