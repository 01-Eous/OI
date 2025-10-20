#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
int h[305];
int dp[305][305];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    m = n - m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < i; k++)
                dp[i][j] = min(dp[i][j],dp[k][j - 1] + max(0LL,h[i] - h[k]));
    int ans = inf;
    for (int i = m; i <= n; i++)
        ans = min(ans,dp[i][m]);
    cout << ans;
    return 0;
}