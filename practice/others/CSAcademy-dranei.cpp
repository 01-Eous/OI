#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,q,tim,idx;
int a[maxn],head[maxn];
int siz[maxn],dep[maxn];
int fa[maxn],son[maxn],top[maxn];
int dfn[maxn],rnk[maxn],ed[maxn];
struct edge{int v,nxt;}e[maxn << 1];
struct Nahida
{
    int l,r,sum,tag;
    void tag_down(int x)
    {
        sum += (r - l + 1) * x;
        tag += x;
    }
}tree[maxn << 2];
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
    dfn[u] = ++tim,rnk[tim] = u;
    top[u] = tp;
    if (son[u])
        dfs2(son[u],tp);
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa[u] && v != son[u])
            dfs2(v,v);
    ed[u] = tim;
}
void push_up(int rt){tree[rt].sum = tree[ls].sum + tree[rs].sum;}
void push_down(int rt)
{
    int &tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(tag);
    tree[rs].tag_down(tag);
    tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].tag = 0;
    if (l == r)
    {
        tree[rt].sum = a[rnk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    push_up(rt);
}
int que(int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
        return tree[rt].sum;
    push_down(rt);
    int mid = (l + r) >> 1;
    if (x <= mid)
        return que(x,ls);
    else
        return que(x,rs);
}
signed main()
{
    scanf("%lld%lld",&n,&q);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs1(1,0),dfs2(1,1);
    build(1,tim,1);
    int op,x,y,z;
    while (q--)
    {
        scanf("%lld",&op);
        if (op == 1)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            int u = 0;
            while (y && top[y] != top[x])
                u = top[y],y = fa[top[y]];
            if (dep[y] < dep[x])
            {
                upd(1,tim,z);
                upd(dfn[x],ed[x],-z);
                continue;
            }
            if (dep[y] > dep[x])
                u = son[x];
            upd(dfn[u],ed[u],z);
        }
        else
        {
            scanf("%lld",&x);
            printf("%lld\n",que(dfn[x]));
        }
    }
    return 0;
}