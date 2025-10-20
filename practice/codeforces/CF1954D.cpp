#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
int a[5005],sum[5005][5005],dp[5005][5005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 5000; j++)
        {
            if (j >= a[i])
                dp[i][j] = (dp[i][j] + sum[i - 1][j - a[i]]) % mod;
            sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5000; j++)
            ans = (ans + dp[i][j] * max(a[i],(j - 1) / 2 + 1)) % mod;
    cout << ans;
    return 0;
}