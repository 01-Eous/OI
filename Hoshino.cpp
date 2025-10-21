#include <bits/extc++.h>
using namespace std;
#define int long long 

constexpr int MAXN = 1e4 + 5,MAXM = 1e5 + 5,MOD = 998244353;
int T,m,n,inv,fac[MAXM],ifac[MAXM],siz[MAXN],cntLeaf[MAXN],dp[MAXN][MAXN],f[MAXN];
vector<int> g[MAXN];
inline int qpow(int b,int p)
{
    int res = 1;
    while(p)
    {
        if(p & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}
inline void preProcess(int n)
{
    fac[0] = 1;
    for(int i = 1;i <= n;i++)
        fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = qpow(fac[n],MOD - 2);
    for(int i = n - 1;i >= 0;i--)
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
}
inline void DP(int u)
{
    siz[u] = 1,cntLeaf[u] = 0;
    memset(dp[u],0,sizeof(int) * (n + 1));
    if(g[u].empty())
    {
        dp[u][1] = cntLeaf[u] = 1;
        return ;
    }
    dp[u][0] = 1;
    for(int v : g[u])
    {
        DP(v);
        for(int i = 0;i < siz[u] + cntLeaf[u];i++)
        {
            for(int j = 0;j < siz[v] + cntLeaf[v];j++)
                f[i + j] = (f[i + j] + dp[u][i] * dp[v][j] % MOD) % MOD;
        }
        siz[u] += siz[v],cntLeaf[u] += cntLeaf[v];
        for(int i = 0;i < siz[u] + cntLeaf[u];i++)
            dp[u][i] = f[i],f[i] = 0;
    }
    for(int i = siz[u] + cntLeaf[u];i;i--)
        dp[u][i] = (dp[u][i] * i % MOD + (siz[u] - 1) * inv % MOD * dp[u][i - 1] % MOD) % MOD;
}
inline void Solve()
{
    cin >> n;
    inv = qpow(n - 1,MOD - 2);
    for(int i = 1;i <= n;i++)
        g[i].clear();
    for(int i = 2,v;i <= n;i++)
    {
        cin >> v;
        g[v].emplace_back(i);
    }
    DP(1);
    int ans = 0;
    for(int i = cntLeaf[1];i <= min(n - 1,m) + cntLeaf[1];i++)
        ans = (ans + dp[1][i] * fac[m] % MOD * ifac[m - i + cntLeaf[1]] % MOD) % MOD;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> T >> m;
    preProcess(1e5);
    while(T--)
       Solve();
}