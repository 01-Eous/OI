#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int const maxn = 2005;
int n,v,m,e;
int c[maxn],d[maxn];
double k[maxn],dp[maxn][maxn][2],ans = inf;
double f[305][305];
signed main()
{
    scanf("%d%d%d%d",&n,&m,&v,&e);
    for (int i = 1; i <= n; i++)
        scanf("%d",c + i);
    for (int i = 1; i <= n; i++)
        scanf("%d",d + i);
    for (int i = 1; i <= n; i++)
        scanf("%lf",k + i);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            f[i][j] = inf;
    for (int i = 1; i <= v; i++)
        f[i][i] = 0;
    for (int i = 1; i <= e; i++)
    {
        int u,v1,w;
        scanf("%d%d%d",&u,&v1,&w);
        f[u][v1] = f[v1][u] = min(f[u][v1],(double)w);
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (f[i][k] != inf && f[k][j] != inf)
                    f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j][0] = dp[i][j][1] = inf;
    dp[1][0][0] = dp[1][1][1] = 0.0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= min(m,i); j++)
        {
            dp[i][j][0] = min(dp[i - 1][j][0] +
                                  f[c[i - 1]][c[i]],

                              dp[i - 1][j][1] +
                                  k[i - 1] * f[d[i - 1]][c[i]] +
                                  (1.0 - k[i - 1]) * f[c[i - 1]][c[i]]);
            if (j)
                dp[i][j][1] = min(dp[i - 1][j - 1][0] +
                                      k[i] * f[c[i - 1]][d[i]] +
                                      (1.0 - k[i]) * f[c[i - 1]][c[i]],

                                  dp[i - 1][j - 1][1] +
                                      f[d[i - 1]][d[i]] * k[i - 1] * k[i] +
                                      f[c[i - 1]][d[i]] * (1.0 - k[i - 1]) * k[i] +
                                      f[d[i - 1]][c[i]] * k[i - 1] * (1.0 - k[i]) +
                                      f[c[i - 1]][c[i]] * (1.0 - k[i - 1]) * (1.0 - k[i]));
        }
    }
    for (int i = 0; i <= m; i++)
        ans = min(ans,min(dp[n][i][0],dp[n][i][1]));
    printf("%.2lf",ans);
    return 0;
}