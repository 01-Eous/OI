#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod;
using namespace std;
const int mod = 12345678;
int n,m,k;
int dp[155][155][25][25];
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int x = 0; x <= k; x++)
            {
                for (int y = 0; y <= k; y++)
                {
                    int tmp = dp[i][j][x][y];
                    add(dp[i + 1][j][x + 1][max(0LL,y - 1)],tmp);
                    add(dp[i][j + 1][max(0LL,x - 1)][y + 1],tmp);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            add(ans,dp[n][m][i][j]);
    printf("%lld",ans);
    return 0;
}