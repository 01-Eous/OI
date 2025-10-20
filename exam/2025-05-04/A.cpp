#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define chkmin(x,y) (x = min(x,y))
using namespace std;
int n,ans = inf;
int a[755],sum[755];
int dp[2][755][755];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1,greater<>());
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    memset(dp,0x3f,sizeof dp);
    dp[0][1][1] = 0;
    for (int i = 0; i <= n; i++)
    {
        bool cur = i & 1,nxt = !cur;
        memset(dp[nxt],0x3f,sizeof dp[nxt]);
        for (int x = 0; x <= n; x++)
        {
            for (int y = 0; y <= n; y++)
            {
                if (dp[cur][x][y] + sum[n] - sum[i] >= ans)
                    continue;
                if (i == n)
                {
                    chkmin(ans,dp[cur][x][y] + sum[n] - sum[i]);
                    continue;
                }
                chkmin(dp[cur][y][x + y],dp[cur][x][y] + sum[n] - sum[i]);
                if (x && y)
                    chkmin(dp[nxt][x - 1][y - 1],dp[cur][x][y] + a[i + 1]);
            }
        }
    }
    printf("%lld",ans - sum[n]);
    return 0;
}