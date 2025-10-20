#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,del,rt,tim;
int siz[maxn],wei[maxn],dep[maxn],col[maxn];
vector<int> g[maxn];
void dfs1(int u,int fa)
{
    siz[u] = 1;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],n - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int fa)
{
    dep[u] = dep[fa] + 1;
    for (auto v : g[u])
        if (v != fa)
            dfs2(v,u);
}
void dfs3(int u,int fa)
{
    col[u] = tim++ % (n >> 1) + 1;
    for (auto v : g[u])
        if (v != fa && v != del)
            dfs3(v,u);
}
void solve()
{
    scanf("%d",&n);
    rt = del = 0;
    memset(siz,0,sizeof(int) * (n + 5));
    memset(wei,0,sizeof(int) * (n + 5));
    memset(dep,0,sizeof(int) * (n + 5));
    memset(col,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    wei[rt] = inf;
    dfs1(1,0);
    dfs2(rt,0);
    dep[del] = inf;
    for (int i = 1; i <= n; i++)
        if (i != rt && g[i].size() == 1 && dep[del] > dep[i])
            del = i;
    dfs3(rt,0);
    printf("%d %d\n",del,g[del][0]);
    int tmp = max(del,g[del][0]);
    for (int i = 1; i <= n; i++)
    {
        if (del != tmp)
        {
            if (i == tmp)
                printf("0 ");
            else if (i == del)
                printf("%d ",col[tmp]);
            else
                printf("%d ",col[i]);
        }
        else
            printf("%d ",col[i]);
    }
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}