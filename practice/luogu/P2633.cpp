#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,m,q,cnt;
int a[maxn],num[maxn],head[maxn],root[maxn],idx;
int dep[maxn],fa[maxn],top[maxn],son[maxn],siz[maxn];
struct edge{int v,nxt;}e[maxn << 1];
struct Nahida{int lson,rson,val;}tree[maxn * 50];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int build(int l,int r)
{
    int rt = ++cnt;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    ls = build(l,mid);
    rs = build(mid + 1,r);
    return rt;
}
int upd(int pos,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].val++;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,l,mid,ls);
    else
        rs = upd(pos,mid + 1,r,rs);
    return rt;
}
int que(int u,int v,int lca,int fa,int l,int r,int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int tmp = tree[tree[u].lson].val + tree[tree[v].lson].val - tree[tree[lca].lson].val - tree[tree[fa].lson].val;
    if (k <= tmp)
        return que(tree[u].lson,tree[v].lson,tree[lca].lson,tree[fa].lson,l,mid,k);
    else
        return que(tree[u].rson,tree[v].rson,tree[lca].rson,tree[fa].rson,mid + 1,r,k - tmp);
}
void dfs1(int u,int pre)
{
    fa[u] = pre,dep[u] = dep[pre] + 1;
    siz[u] = 1;
    root[u] = upd(a[u],1,m,root[pre]);
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num + 1,num + n + 1);
    m = unique(num + 1,num + n + 1) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1,num + m + 1,a[i]) - num;
    root[0] = build(1,m);
    int u,v,k;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v);
        adde(v,u);
    }
    dfs1(1,0);
    dfs2(1,1);
    while (q--)
    {
        static int lst = 0;
        cin >> u >> v >> k;
        u ^= lst;
        int tmp = lca(u,v);
        cout << (lst = num[que(root[u],root[v],root[tmp],root[fa[tmp]],1,m,k)]) << '\n';
    }
    return 0;
}