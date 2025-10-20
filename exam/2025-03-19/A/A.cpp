#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m,_max;
bool vis[maxn];
int fa[maxn],siz[maxn];
int a[maxn],p[maxn],ans[maxn];
vector<int> g[maxn];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x == y)
        return;
    siz[x] += siz[y];
    fa[y] = x;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    while (m--)
    {
        static int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld",p + i);
    iota(fa + 1,fa + n + 1,1);
    ans[n] = 0;
    for (int i = n; i > 1; i--)
    {
        int u = p[i];
        vis[u] = 1;
        for (auto v : g[u])
            if (vis[v])
                merge(u,v);
        siz[find(u)] += a[u];
        ans[i - 1] = max(ans[i],siz[find(u)]);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld\n",ans[i]);
    return 0;
}