#include<bits/extc++.h>
using namespace std;
const int maxn = 1 << 16 | 5;
int n,m;
bool f[maxn];
int u[4005],v[4005];
int g[20],col[20],dp[maxn],x[maxn];
signed main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",u + i,v + i);
        g[u[i]] |= 1 << (v[i] - 1);
        g[v[i]] |= 1 << (u[i] - 1);
    }
    f[0] = 1;
    for (int s = 0; s < 1 << n; s++)
    {
        if (!f[s])
            continue;
        for (int i = 1; i <= n; i++)
            if (!((s >> (i - 1)) & 1) && !(s & g[i]))
                f[s | (1 << (i - 1))] = 1;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int s = 1; s < 1 << n; s++)
        for (int t = s; t; t = s & (t - 1))
            if (f[t] && dp[s ^ t] + 1 < dp[s])
                dp[s] = dp[s ^ t] + 1,x[s] = t;
    printf("%d\n",dp[(1 << n) - 1] - 1);
    int tmp = (1 << n) - 1;
    while (tmp)
    {
        for (int i = 1; i <= n; i++)
            if ((x[tmp] >> (i - 1)) & 1)
                col[i] = dp[tmp];
        tmp ^= x[tmp];
    }
    for (int i = 1; i <= m; i++)
    {
        if (col[u[i]] > col[v[i]])
            swap(u[i],v[i]);
        printf("%d %d\n",u[i],v[i]);
    }
    return 0;
}