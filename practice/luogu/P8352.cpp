#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 1e9 + 7;
int n,k,idx;
int head[1005],siz[1005];
int dp[1005][5005][7],tmp[5005][7];
struct edge{int v,nxt;}e[2005];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    siz[u] = 1;
    for (int i = 1; i <= k; i++)
        dp[u][0][i] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        memcpy(tmp,dp[u],sizeof(tmp));
        memset(dp[u],0,sizeof(dp[u]));
        for (int i = 0; i < siz[u] * k; i++)
            for (int j = 0; j <= k; j++)
                if (tmp[i][j])
                    for (int _i = 0; _i < siz[v] * k; _i++)
                        for (int _j = 0; _j <= k; _j++)
                            if (dp[v][_i][_j])
                                add(dp[u][i + _i + _j][max(i + j + _i,i + _i + _j) - (i + _i + _j)],tmp[i][j] * dp[v][_i][_j]);
        siz[u] += siz[v];
    }
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    for (int i = 1; i <= n * k; i++)
    {
        int ans = 0;
        for (int j = 0; j <= min(i,k); j++)
            add(ans,dp[1][i - j][j]);
        printf("%lld\n",ans);
    }
    return 0;
}