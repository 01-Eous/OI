#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 998244353;
const int maxn = 1 << 18 | 5;
int n,q,rt,s,idx = 1;
int head[20],k[20],b[20],sum[maxn];
struct edge{int v,nxt;}e[40];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
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
void dfs(int u,int fa)
{
    if ((s >> (u - 1)) & 1)
    {
        k[u] = b[u] = 0;
        return;
    }
    int deg = 0,sumk = 0,sumb = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        deg++;
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        sumk = (sumk + k[v]) % mod;
        sumb = (sumb + b[v]) % mod;
    }
    k[u] = inv((deg - sumk + mod) % mod);
    b[u] = (deg + sumb) % mod * k[u] % mod;
}
signed main()
{
    scanf("%lld%lld%lld",&n,&q,&rt);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    for (s = 1; s < 1 << n; s++)
    {
        dfs(rt,0);
        sum[s] = (__builtin_popcountll(s) & 1 ? 1 : mod - 1) * b[rt] % mod;
    }
    for (int i = 1; i <= n; i++)
        for (s = 1; s < 1 << n; s++)
            if ((s >> (i - 1)) & 1)
                sum[s] = (sum[s] + sum[s ^ (1 << (i - 1))]) % mod;
    int k,x;
    while (q--)
    {
        scanf("%lld",&k);
        s = 0;
        while (k--)
        {
            scanf("%lld",&x);
            s |= 1 << (x - 1);
        }
        printf("%lld\n",sum[s]);
    }
    return 0;
}