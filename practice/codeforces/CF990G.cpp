#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n;
ll f[maxn];
bool vis[maxn];
int fa[maxn],siz[maxn];
vector<int> vec[maxn],g[maxn];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x != y)
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j)
                continue;
            vec[j].push_back(i);
            if (x / j != j)
                vec[x / j].push_back(i);
        }
        fa[i] = i,siz[i] = 1;
    }
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= 2e5; i++)
    {
        for (auto u : vec[i])
            vis[u] = 1;
        for (auto u : vec[i])
            for (auto v : g[u])
                if (vis[v])
                    merge(u,v);
        for (auto u : vec[i])
            if (fa[u] == u)
                f[i] += siz[u] * (siz[u] + 1LL) >> 1;
        for (auto u : vec[i])
            fa[u] = u,siz[u] = 1,vis[u] = 0;
    }
    for (int i = 2e5; i >= 1; i--)
        for (int j = i << 1; j <= 2e5; j += i)
            f[i] -= f[j];
    for (int i = 1; i <= 2e5; i++)
        if (f[i])
            printf("%d %lld\n",i,f[i]);
    return 0;
}