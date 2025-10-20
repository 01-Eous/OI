#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,p;
int c[65],w[65];
int dp1[65][1005][1005],dp2[65][1005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    if (p % c[1])
        return cout << "-1",0;
    memset(dp1,0x3f,sizeof dp1);
    memset(dp2,~0x3f,sizeof dp2);
    dp1[n + 1][m][0] = dp2[n + 1][m][0] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                int l = c[i + 1] / c[i] * k + p / c[i];
                if (l <= j)
                {
                    dp1[i][j][l] = min(dp1[i][j][l],dp1[i + 1][j][k]);
                    dp2[i][j][l] = max(dp2[i][j][l],dp2[i + 1][j][k]);
                }
            }
        }
        for (int j = m; j >= 1; j--)
        {
            for (int k = j; k >= 1; k--)
            {
                dp1[i][j - 1][k - 1] = min(dp1[i][j][k] + w[i],dp1[i][j - 1][k - 1]);
                dp2[i][j - 1][k - 1] = max(dp2[i][j][k] + w[i],dp2[i][j - 1][k - 1]);
            }
        }
        p %= c[i];
    }
    if (dp2[1][0][0] < 0)
        return cout << "-1",0;
    cout << dp1[1][0][0] << ' ' << dp2[1][0][0];
    return 0;
}