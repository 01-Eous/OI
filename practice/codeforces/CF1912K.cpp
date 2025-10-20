#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
int a[maxn],dp[maxn][2][2],cnt[2];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] &= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % mod;
                if (!((k + j + a[i]) & 1))
                {
                    dp[i][j][a[i]] = (dp[i][j][a[i]] + dp[i - 1][k][j]) % mod;
                    ans = (ans + dp[i - 1][k][j]) % mod;
                }
            }
        }
        for (int j = 0; j < 2; j++)
            dp[i][j][a[i]] = (dp[i][j][a[i]] + cnt[j]) % mod;
        cnt[a[i]]++;
    }
    cout << ans;
    return 0;
}