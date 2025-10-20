#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int> a(n + 5),dp(n + 5,inf);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[n + 1] = 0;
    for (int i = n + 1; i >= 2; i--)
    {
        int pos = n + 1,min1 = inf;
        for (int j = i - 1; j >= 1; j--)
        {
            if (min1 > a[j])
                pos = j,min1 = a[j];
            dp[j] = min(dp[j],dp[i] + i - pos + i - j - 2 + min1 * (i - j));
        }
    }
    cout << dp[1] << '\n';
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