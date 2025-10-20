#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,idx;
int dp[5005][5005],tmp[5005];
int head[5005],f[5005],siz[5005];
struct edge{int v,nxt;}e[10005];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    siz[u] = 1;
    dp[u][1] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        for (int j = 1; j <= siz[u]; j++)
            tmp[j] = dp[u][j],dp[u][j] = 0;
        for (int j = 1; j <= siz[u]; j++)
        {
            for (int k = 1; k <= siz[v]; k++)
            {
                dp[u][j] = (dp[u][j] + tmp[j] * dp[v][k] % mod * (mod - f[k])) % mod;
                dp[u][j + k] = (dp[u][j + k] + tmp[j] * dp[v][k]) % mod;
            }
        }
        siz[u] += siz[v];
    }
}
signed main()
{
    scanf("%lld",&n);
    f[0] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 2] * (i - 1) % mod;
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[1][i] * f[i]) % mod;
    printf("%lld",ans);
    return 0;
}