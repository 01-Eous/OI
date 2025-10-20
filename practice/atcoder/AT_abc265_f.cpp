#include<bits/extc++.h>
#define int long long
#define add(x,y) (x = ((x + y) % mod + mod) % mod)
using namespace std;
const int mod = 998244353;
int n,d;
int p[105],q[105];
int dp[1005][1005];
int pre[1005][1005],sum[1005][1005];
signed main()
{
    scanf("%lld%lld",&n,&d);
    for (int i = 1; i <= n; i++)
        scanf("%lld",p + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld",q + i);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = abs(p[i] - q[i]);
        for (int j = 0; j <= d; j++)
        {
            for (int k = 0; k <= d; k++)
            {
                if (j && k)
                    sum[j][k] = (dp[j][k] + sum[j - 1][k - 1]) % mod;
                else
                    sum[j][k] = dp[j][k];
                if (j)
                    pre[j][k] = (dp[j][k] + pre[j - 1][k + 1]) % mod;
                else
                    pre[j][k] = dp[j][k];
            }
        }
        for (int j = 0; j <= d; j++)
        {
            for (int k = 0; k <= d; k++)
            {
                dp[j][k] = 0;
                if (j > x && k)
                    add(dp[j][k],sum[j - x - 1][k - 1]);
                if (k > x && j)
                    add(dp[j][k],sum[j - 1][k - x - 1]);
                int tx,ty;
                tx = j - x,ty = k;
                if (tx < 0)
                    ty += tx,tx = 0;
                if (tx >= 1 && ty + 1 >= 0)
                    add(dp[j][k],-pre[tx - 1][ty + 1]);
                tx = j,ty = k - x;
                if (ty < 0)
                    tx += ty,ty = 0;
                if (tx >= 0 && ty >= 0)
                    add(dp[j][k],pre[tx][ty]);
            }
        }
    }
    int ans = 0;    
    for (int i = 0; i <= d; i++)
        for (int j = 0; j <= d; j++)
            add(ans,dp[i][j]);
    printf("%lld\n",ans);
    return 0;
}