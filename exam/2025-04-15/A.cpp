#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,sc,tim;
bool vis[maxn];
int a[maxn];
int fac[maxn],inv[maxn],p2[maxn];
int dfn[maxn],low[maxn],siz[maxn];
stack<int> stk;
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
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
void init(int n = 1e6)
{
    fac[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        p2[i] = (p2[i - 1] << 1) % mod;
    }
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
void dfs(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    stk.push(u);
    if (!dfn[a[u]])
    {
        dfs(a[u]);
        low[u] = min(low[u],low[a[u]]);
    }
    else if (vis[a[u]])
        low[u] = min(low[u],dfn[a[u]]);
    if (dfn[u] == low[u])
    {
        int lst = 0;
        sc++;
        while (lst != u)
        {
            lst = stk.top();
            stk.pop();
            siz[sc]++;
            vis[lst] = 0;
        }
    }
}
signed main()
{
    init();
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    int ans = 0;
    for (int i = 1; i <= sc; i++)
    {
        ans = (ans + p2[n - siz[i]]) % mod;
        // 这里没有一个被拿走，外面爱咋取咋取
        for (int j = 1; j < siz[i]; j++)// 枚举这里被取了多少个
            ans = (ans + (siz[i] - j) * p2[n - siz[i]] % mod * c(siz[i],j)) % mod;
        // 这里剩了 siz[i] - j 个点，组成 siz[i] - j 个 scc
        // 外面依然爱咋取咋取，里面取 j 个有 c(siz[i],j) 种方案
    }
    printf("%lld",ans);
    return 0;
}