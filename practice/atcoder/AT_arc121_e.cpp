#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,idx;
int fac[2005],inv[2005];
int head[2005],siz[2005];
int dp[2005][2005],tmp[2005];
struct edge{int v,nxt;}e[2005];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void init()
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
}
void dfs(int u)
{
    siz[u] = 1;
    dp[u][0] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        dfs(v);
        memset(tmp,0,sizeof(int) * (siz[u] + siz[v] + 5));
        for (int j = 0; j <= siz[u]; j++)
            for (int k = 0; k <= siz[v]; k++)
                tmp[j + k] = (tmp[j + k] + dp[u][j] * dp[v][k]) % mod;
        siz[u] += siz[v];
        memcpy(dp[u],tmp,sizeof(int) * (siz[u] + 5));
    }
    for (int i = siz[u]; i; i--)
        dp[u][i] = (dp[u][i] + dp[u][i - 1] * (siz[u] - i)) % mod;
}
signed main()
{
    scanf("%lld",&n),init();
    for (int i = 2,x; i <= n; i++)
        scanf("%lld",&x),adde(x,i);
    dfs(1);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + (i & 1 ? -1 : 1) * dp[1][i] * fac[n - i] % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}