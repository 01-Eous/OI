#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,h;
int p[105],c[105],dp[100005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    memset(dp,2,sizeof(dp));
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> c[i];
    dp[0] = 0;
    for (int i = 1; i <= (h << 1); i++)
        for (int j = 1; j <= n; j++)
            if (i >= p[j])
                dp[i] = min(dp[i - p[j]] + c[j],dp[i]);
    int ans = inf;
    for (int i = h; i <= (h << 1); i++)
        ans = min(ans,dp[i]);
    cout << ans;
    return 0;
}