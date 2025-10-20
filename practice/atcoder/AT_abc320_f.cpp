#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define chkmin(x,y) (x = min(x,y))
using namespace std;
int n,m;
int dp[305][305][305];
int x[305],p[305],f[305];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i < n; i++)
        cin >> p[i] >> f[i];
    memset(dp,0x3f,sizeof dp);
    dp[0][m][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int dis = x[i] - x[i - 1];
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                int tj = j - dis,tk = k + dis;
                if (tj < 0 || tk > m)
                    continue;
                chkmin(dp[i][tj][tk],dp[i - 1][j][k]);
                chkmin(dp[i][min(m,tj + f[i])][tk],dp[i - 1][j][k] + p[i]);
                chkmin(dp[i][tj][max(0LL,tk - f[i])],dp[i - 1][j][k] + p[i]);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= i; j++)
            chkmin(ans,dp[n][i][j]);
    cout << (ans != inf ? ans : -1);        
    return 0;
}