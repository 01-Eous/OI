#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e4 + 5;
int n,q,idx;
ll a[maxn];
int fa[maxn],son[maxn],top[maxn];
int head[maxn],dep[maxn],siz[maxn];
struct edge{int v,nxt;}e[maxn << 1];
class linear_basis
{
    ll d[65];
    int pos[65];
    public:
    void ins(ll x,int p)
    {
        for (int i = 61; i >= 0; i--)
        {
            if ((x >> i) & 1)
            {
                if (!d[i])
                {
                    d[i] = x;
                    pos[i] = p;
                    break;
                }
                else if (pos[i] < p)
                {
                    swap(d[i],x);
                    swap(pos[i],p);
                }
                x ^= d[i];
            }
        }
    }
    void merge(const linear_basis &x)
    {
        for (int i = 61; i >= 0; i--)
            ins(x.d[i],x.pos[i]);
    }
    ll que(int p)
    {
        ll res = 0;
        for (int i = 61; i >= 0; i--)
            if (pos[i] >= p && (res ^ d[i]) > res)
                res ^= d[i];
        return res;
    }
}b[maxn];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    fa[u] = pre,siz[u] = 1;
    dep[u] = dep[pre] + 1;
    b[u] = b[pre],b[u].ins(a[u],dep[u]);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre)
            continue;
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
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa[u] && v != son[u])
            dfs2(v,v);
}
int lca(int u,int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
signed main()
{
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int u,v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs1(1,0),dfs2(1,1);
    while (q--)
    {
        scanf("%d%d",&u,&v);
        linear_basis tmp = b[u];
        tmp.merge(b[v]);
        printf("%lld\n",tmp.que(dep[lca(u,v)]));
    }
    return 0;
}