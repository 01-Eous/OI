#include <bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
unsigned s;
int n,q,root,idx,lst;
int head[maxn],dep[maxn],f[maxn][25];
struct edge
{
    int v,nxt;
} e[maxn];
unsigned get(unsigned x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    dep[u] = dep[f[u][0]] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
        dfs(e[i].v);
}
inline int que(int u,int k)
{
    for (int i = 20; ~i; i--)
        if (k & (1 << i))
            u = f[u][i];
    return u;
}
signed main()
{
    scanf("%d%d%u",&n,&q,&s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&f[i][0]);
        if (f[i][0])
            adde(f[i][0],i);
        else
            root = i;
    }
    dfs(root);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            f[j][i] = f[f[j][i - 1]][i - 1];
    int u,k;
    ll ans = 0;
    for (int i = 1; i <= q; i++)
    {
        u = (get(s) ^ lst) % n + 1;
        k = (get(s) ^ lst) % dep[u];
        lst = que(u,k);
        ans ^= (ll)i * lst;
    }
    printf("%lld",ans);
    return 0;
}