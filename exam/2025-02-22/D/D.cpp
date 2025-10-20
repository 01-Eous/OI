#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
int num[(int)1e5 + 5],cnt;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    num[++cnt] = 0;
    vector<int>a(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[++cnt] = a[i];
    }
    sort(num + 1,num + cnt + 1);
    m = unique(num + 1,num + cnt + 1) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1,num + m + 1,a[i]) - num;
    vector<vector<int>>dp(n + 5,vector<int>(m + 5,inf));
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                dp[i][j] = min(dp[i][j],dp[i - 1][k] + abs(num[k] - num[j]) + abs(num[a[i]] - num[a[i - 1]]));
                dp[i][j] = min(dp[i][j],dp[i - 1][k] + abs(num[k] - num[a[i]]) + abs(num[j] - num[a[i - 1]]));
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= m; i++)
        ans = min(ans,dp[n][i]);
    cout << ans;
    return 0;
}
