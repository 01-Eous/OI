#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
int n,m,idx,invn;
int dp[maxn][maxn];
int fac[maxm],inv[maxm];
int head[maxn],siz[maxn],tmp[maxn],cnt[maxn];
struct{int v,nxt;}e[maxn];
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
void init(int n = 1e5)
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n; i > 0; i--)
        inv[i - 1] = inv[i] * i % mod;
}
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    memset(dp[u],0,sizeof(int) * (n + 5));
    cnt[u] = 0,siz[u] = 1;
    if (!head[u])
    {
        dp[u][1] = cnt[u] = 1;
        return;
    }
    dp[u][0] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        dfs(v);
        for (int j = 0; j < siz[u] + cnt[u]; j++)
            for (int k = 0; k < siz[v] + cnt[v]; k++)
                tmp[j + k] = (tmp[j + k] + dp[u][j] * dp[v][k] % mod) % mod;
        siz[u] += siz[v],cnt[u] += cnt[v];
        memcpy(dp[u],tmp,sizeof(int) * (siz[u] + cnt[u]));
        memset(tmp,0,sizeof(int) * (siz[u] + cnt[u]));
    }
    for (int i = siz[u] + cnt[u]; i; i--)
        dp[u][i] = (dp[u][i] * i + dp[u][i - 1] * (siz[u] - 1) % mod * invn) % mod;
}
void solve()
{
    cin >> n,idx = 0;
    invn = binpow(n - 1,mod - 2);
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 2,x; i <= n; i++)
    {
        cin >> x;
        adde(x,i);
    }
    dfs(1);
    int ans = 0;
    for (int i = cnt[1]; i <= min(n - 1,m) + cnt[1]; i++)
        ans = (ans + dp[1][i] * fac[m] % mod * inv[m - i + cnt[1]]) % mod;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t >> m;
    while (t--)
        solve();
    return 0;
}