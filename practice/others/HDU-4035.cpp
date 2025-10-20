#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxn = 1e5 + 5;
const ld eps = 1e-12;
int n;
int deg[maxn];
ld k[maxn],e[maxn],t[maxn];
ld a[maxn],b[maxn],c[maxn];
vector<int> g[maxn];
bool dfs(int u,int fa)
{
    if (deg[u] == 1 && fa)
    {
        a[u] = k[u];
        b[u] = c[u] = t[u];
        return 1;
    }
    ld suma = 0,sumb = 0,sumc = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        if (!dfs(v,u))
            return 0;
        suma += a[v];
        sumb += b[v];
        sumc += c[v];
    }
    ld d = t[u] / deg[u],tmp = 1 - d * sumb;
    if (fabs(tmp) < eps)
        return 0;
    a[u] = (k[u] + d * suma) / tmp;
    b[u] = d / tmp;
    c[u] = (t[u] + d * sumc) / tmp;
    return 1;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear(),deg[i] = 0;
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%Lf%Lf",k + i,e + i);
        k[i] /= 100.0,e[i] /= 100.0;
        t[i] = 1.0 - k[i] - e[i];
    }
    if (!dfs(1,0) || fabs(1 - a[1]) < eps)
        puts("impossible");
    else
        printf("%.6Lf\n",c[1] / (1 - a[1]));
}
signed main()
{
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    {
        printf("Case %d: ",i);
        solve();
    }
    return 0;
}