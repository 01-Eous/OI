#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
int fac[505],tot[505],siz[505];
int dp[505][505],f[505][505],tmp[505];
vector<int> g[505];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void init(int n = 500)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
}
int dfs1(int u,int fa)
{
    int res = 1;
    siz[u] = 1,tot[u] = 0;
    for (auto &v : g[u])
    {
        if (v == fa)
            continue;
        res = res * dfs1(v,u) % mod;
        siz[u] += siz[v],tot[u]++;
    }
    return res * fac[tot[u]] % mod;
}
void dfs2(int u,int fa)
{
    memset(f,0,sizeof f);
    f[0][0] = 1;
    for (auto &v : g[u])
    {
        if (v == fa)
            continue;
        for (int i = tot[u]; i >= 1; i--)
            for (int j = siz[u]; j >= siz[v]; j--)
                f[i][j] = (f[i][j] + f[i - 1][j - siz[v]]) % mod;
    }
    for (auto &v : g[u])
    {
        if (v == fa)
            continue;
        for (int i = 1; i <= tot[u]; i++)
            for (int j = siz[v]; j <= siz[u]; j++)
                f[i][j] = (f[i][j] - f[i - 1][j - siz[v]] + mod) % mod;
        memset(tmp,0,sizeof tmp);
        for (int i = 0; i < tot[u]; i++)
            for (int j = 0; j <= siz[u]; j++)
                tmp[j + 1] = (tmp[j + 1] + fac[i] * fac[tot[u] - 1 - i] % mod * f[i][j] % mod) % mod;
        for (int i = 1; i <= n; i++)
            for (int j = 1; i + j <= n; j++)
                dp[v][i + j] = (dp[v][i + j] + dp[u][i] * tmp[j]) % mod;
        for (int i = tot[u]; i >= 1; i--)
            for (int j = siz[u]; j >= siz[v]; j--)
                f[i][j] = (f[i][j] + f[i - 1][j - siz[v]]) % mod;
    }
    for (auto v : g[u])
        if (v != fa)
            dfs2(v,u);
}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp[1][1] = dfs1(1,0);
    dfs2(1,0);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum = (sum + dp[i][j]) % mod;
        int tmp = binpow(sum,mod - 2);
        for (int j = 1; j <= n; j++)
            printf("%lld%c",dp[i][j] * dp[1][1] % mod * tmp % mod," \n"[j == n]);
    }
    return 0;
}