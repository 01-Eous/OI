#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,ans;
int g[50];
void dfs(int r,int p,int x)
{
    if (!p && !x)
        ans = max(ans,(int)__builtin_popcountll(r));
    int u = __builtin_ctzll(p | x),tmp = p & ~g[u];
    for (int v = 0; v < n; v++)
    {
        if ((tmp >> v) & 1)
        {
            dfs(r | (1LL << v),p & g[v],x & g[v]);
            p ^= 1LL << v;
            x |= 1LL << v;
        }
    }
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    memset(g,0,sizeof(int) * (n + 5));
    int u,v;
    ans = 0;
    while (m--)
    {
        scanf("%lld%lld",&u,&v);
        u--,v--;
        g[u] |= 1LL << v;
        g[v] |= 1LL << u;
    }
    dfs(0,(1LL << n) - 1,0);
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}