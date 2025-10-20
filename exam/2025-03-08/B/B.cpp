#include<bits/extc++.h>
#define int long long
using namespace std;
const int py = 2000;
const int mod = 1e9 + 7;
int n;
int l[55],r[55],dp[55][55][4005],sum[55][55][4005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= py << 1; k++)
            if (k != py || n == 1)
                dp[i][i][k] = sum[i][i][k] = r[i] - l[i] + 1 - (l[i] <= abs(k - py) && abs(k - py) <= r[i]);
        for (int k = 1; k <= py << 1; k++)
            sum[i][i][k] += sum[i][i][k - 1];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
        {
            for (int k = 0; k <= py; k++)
                if ((i == 1 && j == n) || k != py)
                    dp[i][j][k] = (sum[i + 1][j][k + r[i]] - sum[i + 1][j][k + l[i] - 1] + mod) % mod;
            for (int k = py + 1; k <= py << 1; k++)
                dp[i][j][k] = (sum[i][j - 1][k - l[j]] - sum[i][j - 1][k - r[j] - 1] + mod) % mod;
            sum[i][j][0] = dp[i][j][0];
            for (int k = 1; k <= py << 1; k++)
                sum[i][j][k] = (sum[i][j][k - 1] + dp[i][j][k]) % mod;
        }
    }
    cout << dp[1][n][py];
    return 0;
}