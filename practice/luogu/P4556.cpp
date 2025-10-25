#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,idx,m,cnt;
int fa[maxn],son[maxn],top[maxn],ans[maxn];
int head[maxn],root[maxn],siz[maxn],dep[maxn];
struct{int v,nxt;}e[maxn << 1];
struct
{
    int max1,id;
    int lson,rson;
}tree[maxn << 6];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    fa[u] = pre,siz[u] = 1;
    dep[u] = dep[pre] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre)
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
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
void push_up(int rt)
{
    if (tree[ls].max1 >= tree[rs].max1)
    {
        tree[rt].max1 = tree[ls].max1;
        tree[rt].id = tree[ls].id;
    }
    else
    {
        tree[rt].max1 = tree[rs].max1;
        tree[rt].id = tree[rs].id;
    }
}
void upd(int pos,int x,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (l == r)
    {
        tree[rt].id = pos;
        tree[rt].max1 += x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    push_up(rt);
}
int mge(int l,int r,int rt1,int rt2)
{
    if (!rt1 || !rt2)
        return rt1 | rt2;
    if (l == r)
    {
        tree[rt1].max1 += tree[rt2].max1;
        return rt1;
    }
    int mid = (l + r) >> 1;
    tree[rt1].lson = mge(l,mid,tree[rt1].lson,tree[rt2].lson);
    tree[rt1].rson = mge(mid + 1,r,tree[rt1].rson,tree[rt2].rson);
    push_up(rt1);
    return rt1;
}
void dfs3(int u,int pre)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre)
            continue;
        dfs3(v,u);
        root[u] = mge(1,1e5,root[u],root[v]);
    }
    ans[u] = tree[root[u]].max1 ? tree[root[u]].id : 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs1(1,0),dfs2(1,1);
    int x,y,z;
    while (m--)
    {
        cin >> x >> y >> z;
        int anc = lca(x,y);
        upd(z,1,1,1e5,root[x]);
        upd(z,1,1,1e5,root[y]);
        upd(z,-1,1,1e5,root[anc]);
        upd(z,-1,1,1e5,root[fa[anc]]);
    }
    dfs3(1,0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}