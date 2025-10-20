#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,s,t;
int dp[2005][2005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> t;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == s || i == t)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = (j * dp[i - 1][j + 1] + (j - (i > s) - (i > t)) * dp[i - 1][j - 1]) % mod;
        }
    }
    cout << dp[n][1];
    return 0;
}