#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,tim;
int dfn[maxn],ed[maxn],dep[maxn],ans[maxn];
vector<int> g[maxn],vec;
void dfs(int u,int fa)
{
    dfn[u] = ++tim;
    dep[u] = dep[fa] + 1;
    for (auto v : g[u])
        if (v != fa)
            dfs(v,u);
    ed[u] = tim;
}
bool cmp(int x,int y){return dep[x] > dep[y];}
signed main()
{
    scanf("%d%d",&n,&m);
    if (m < n - 1)
        return puts("NO"),0;
    m -= n - 1;
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    vec.resize(n);
    iota(vec.begin(),vec.end(),1);
    sort(vec.begin(),vec.end(),cmp);
    for (auto u : vec)
    {
        if (!m)
            break;
        if (u == 1)
            
        int p = __lg(m + 1);
        int val = (1 << p) - 1;
        if (val > m)
            val = (1 << --p) - 1;
        ans[dfn[u]] += p;
        ans[ed[u] + 1] -= p;
        m -= val;
    }
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];
    puts("YES");
    for (int i = 1; i <= n; i++)
        printf("%d ",ans[dfn[i]]);
    return 0;
}
/*
5 31
2 5
1 4
1 3
2 1
*/
