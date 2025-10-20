#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,k;
int dp[4005][4005],pw[4005];
signed main()
{
    cin >> n >> k;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * k % mod;
    dp[1][1] = k;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int tmp = 0;
        dp[i - 1][0] = dp[i - 1][k];
        for (int j = k; j >= 1; j--)
        {
            if (j != k)
                tmp = (tmp + dp[i - 1][j]) % mod;
            dp[i][j] = (dp[i - 1][j - 1] * (k - j + 1) + tmp) % mod;
        }
        ans = (ans + dp[i][k] * pw[n - i]) % mod;
    }
    cout << ans;
    return 0;
}