#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y + mod) % mod
using namespace std;
const int mod = 998244353;
int n,m;
bool vis[205][205],rec[205],col[205];
int a[205],fac[205],dp[205][205][205][2][2];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
}
signed main()
{
    scanf("%lld",&n);
    m = n,init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (~a[i])
        {
            m--,vis[i][a[i]] = 1;
            rec[i] = col[a[i]] = 1;
        }
    }
    dp[0][0][0][1][1] = 1;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        if (!dp[i][j][k][x][y])
                            continue;
                        int tmp = dp[i][j][k][x][y];
                        if (i <= n && !vis[i + 1][j])
                            add(dp[i + 1][j][k][rec[i + 1]][y],tmp);
                        if (j <= n && !vis[i][j + 1])
                            add(dp[i][j + 1][k][x][col[j + 1]],tmp);
                        if (!x && !y)
                        {
                            if (i <= n && !vis[i + 1][j])
                                add(dp[i + 1][j][k + 1][rec[i + 1]][1],-tmp);
                            if (j <= n && !vis[i + 1][j])
                                add(dp[i][j + 1][k + 1][1][col[j + 1]],-tmp);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = (ans + fac[m - i] * dp[n + 1][n + 1][i][0][0]) % mod;
    printf("%lld",ans);
    return 0;
}