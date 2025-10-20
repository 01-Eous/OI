#include<bits/extc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 2e5 + 5;
char buf[1 << 23],*p1,*p2;
int n,m,q,tot;
int l[maxn],r[maxn];
int fa[maxn],val[maxn];
int siz[maxn],pre[maxn];
int son[maxn],dep[maxn],top[maxn],st[maxn][25];
vector<int> g[maxn];
array<int,3> e[maxn];
inline void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int find(int u){return fa[u] == u ? u : fa[u] = find(fa[u]);}
void kruskal()
{
    iota(fa + 1,fa + n + 1,1);
    tot = n;
    for (int i = 1; i <= m; i++)
    {
        auto [w,u,v] = e[i];
        u = find(u),v = find(v);
        if (u == v)
            continue;
        val[++tot] = w;
        fa[u] = fa[v] = fa[tot] = tot;
        g[tot].push_back(u);
        g[tot].push_back(v);
    }
}
void dfs1(int u,int fat)
{
    siz[u] = 1,pre[u] = fat;
    dep[u] = dep[fat] + 1;
    for (auto v : g[u])
    {
        pre[v] = u;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u,int tp)
{
    top[u] = tp;
    if (son[u])
        dfs2(son[u],tp);
    for (auto v : g[u])
        if (v != son[u] && v != pre[u])
            dfs2(v,v);
}
int lca(int u,int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        u = pre[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
int que(int l,int r)
{
    int k = __lg(r - l + 1);
    return lca(st[l][k],st[r - (1 << k) + 1][k]);
}
signed main()
{
    read(n),read(m),read(q);
    for (int i = 1; i <= m; i++)
    {
        auto &[w,u,v] = e[i];
        read(u),read(v),w = i;
    }
    kruskal();
    dfs1(tot,0);
    dfs2(tot,tot);
    for (int i = 1; i <= n; i++)
        st[i][0] = i;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = lca(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
    int l,r;
    while (q--)
    {
        read(l),read(r);
        printf("%d ",val[que(l,r)]);
    }
    return 0;
}