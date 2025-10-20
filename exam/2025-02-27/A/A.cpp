#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int>b(m + 5),up(m + 5);
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        b[x]++;
    }
    for (int i = 1; i <= m; i++)
        up[i] = max(b[i - 1],b[i]);
    vector<vector<vector<int>>>dp(m + 5);
    dp[0].resize(1),dp[0][0].resize(1);
    for (int i = 1; i <= m; i++)
    {
        dp[i].resize(up[i] + 5);
        for (int j = 0; j <= up[i]; j++)
            dp[i][j].resize(up[i] + 5);
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= b[i]; j++)
        {
            for (int k = 0; k <= b[i - 1]; k++)
            {
                for (int x = (b[i] - j) / 3; x >= 0; x--)
                {
                    if (k + (b[i] - j) - x * 3 > up[i - 1])
                        break;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k + (b[i] - j) - x * 3][(b[i] - j) - x * 3]) % mod;
                }
            }
        }
    }
    cout << dp[m][0][0];
    return 0;
}