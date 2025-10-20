#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,x;
int h[55],c[55],dp[50005];
void solve()
{
    cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> c[i];
        sum += c[i];
    }
    fill(dp + 1,dp + sum + 1,inf);
    int now = dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= c[i]; j--)
        {
            dp[j] = min(dp[j],dp[j - c[i]] + h[i]);
            if (dp[j] > now)
                dp[j] = inf;
        }
        now += x;
    }
    for (int i = sum; i >= 0; i--)
    {
        if (dp[i] < inf)
        {
            cout << i << '\n';
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();    
    return 0;
}