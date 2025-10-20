#include<bits/extc++.h>
#define int long long
#define add(x,y) (x = (x + y) % mod)
using namespace std;
const int maxn = 1 << 20 | 5;
const int mod = 998244353;
const int inv2 = 499122177;
int n,m;
int g[25][25],dp[maxn][25];
signed main()
{
    scanf("%lld%lld",&n,&m);
    int u,v;
    while (m--)
    {
        scanf("%lld%lld",&u,&v);
        g[u][v]++,g[v][u]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            add(ans,g[i][j] * (g[i][j] - 1));
    for (int st = 1; st <= n; st++)
    {
        fill(dp[0],dp[1 << st],0);
        dp[1 << (st - 1)][st] = 1;
        for (int s = 0; s < 1 << st; s++)
        {
            for (int i = 1; i <= st; i++)
            {
                if (s != (1 << (st - 1) | 1 << (i - 1)))
                    add(ans,dp[s][i] * g[st][i]);
                for (int j = 1; j <= st; j++)
                    if (!((s >> (j - 1)) & 1))
                        add(dp[s | (1 << (j - 1))][j],dp[s][i] * g[i][j]);
            }
        }
    }
    printf("%lld",ans * inv2 % mod);
    return 0;
}