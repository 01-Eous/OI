#include<bits/extc++.h>
using namespace std;
const int maxn = 1 << 16 | 5;
int n,m;
bool g[20][20];
int f[maxn],dp[maxn];
signed main()
{
    scanf("%d%d",&n,&m);
    memset(g,1,sizeof g);
    int u,v;
    while (m--)
    {
        scanf("%d%d",&u,&v);
        g[u][v] = g[v][u] = 0;
    }
    for (int s = 0; s < 1 << n; s++)
        for (int i = 1; i <= n; i++)
            if (s & (1 << (i - 1)))
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        f[s] += (s & (1 << (j - 1)) ? !g[i][j] : g[i][j]);
    for (int s = 0; s < 1 << n; s++)
    {
        dp[s] = f[s];
        for (int k = s; k; k = s & (k - 1))
            dp[s] = min(dp[s],dp[s ^ k] + f[k]);
    }
    printf("%d",dp[(1 << n) - 1] >> 1);
    return 0;
}