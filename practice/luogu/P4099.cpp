#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,idx;
int fac[1005],inv[1005];
int head[1005],siz[1005];
int dp[1005][1005],tmp[1005];
struct{int v,w,nxt;}e[2005];
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void init(int n = 1000)
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n; i > 0; i--)
        inv[i - 1] = inv[i] * i % mod;
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void dfs(int u,int fa)
{
    siz[u] = dp[u][1] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        memcpy(tmp,dp[u],sizeof(int) * (siz[u] + 5));
        memset(dp[u],0,sizeof(int) * (siz[u] + siz[v] + 5));
        if (e[i].w)
        {
            for (int p1 = 1; p1 <= siz[u]; p1++)
                for (int p3 = p1; p3 < p1 + siz[v]; p3++)
                    dp[u][p3] = (dp[u][p3] + c(p3 - 1,p1 - 1) * c(siz[u] + siz[v] - p3,siz[u] - p1) % mod * tmp[p1] % mod * (dp[v][siz[v]] - dp[v][p3 - p1] + mod)) % mod;
        }
        else
        {
            for (int p1 = 1; p1 <= siz[u]; p1++)
                for (int p3 = p1 + 1; p3 <= p1 + siz[v]; p3++)
                    dp[u][p3] = (dp[u][p3] + c(p3 - 1,p1 - 1) * c(siz[u] + siz[v] - p3,siz[u] - p1) % mod * tmp[p1] % mod * dp[v][p3 - p1]) % mod;
        }
        siz[u] += siz[v];
    }
    for (int i = 1; i <= siz[u]; i++)
        dp[u][i] = (dp[u][i] + dp[u][i - 1]) % mod;
}
void solve()
{
    cin >> n,idx = 0;
    memset(siz,0,sizeof(int) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    char ch;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> ch >> v;
        adde(u,v,ch == '<');
        adde(v,u,ch == '>');
    }
    dfs(0,-1);
    cout << dp[0][n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}