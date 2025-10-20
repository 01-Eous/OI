#include<bits/extc++.h>
#define int long long
#define inf 123456789123456789
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,m,tim;
int head[maxn],idx;
int siz[maxn],son[maxn];
int dfn[maxn],rnk[maxn];
int top[maxn],fa[maxn],dep[maxn],dis[maxn];
struct edge{int v,w,nxt;}e[maxn << 1];
struct line
{
    int k,b;
    line(int k = 0,int b = inf):k(k),b(b){};
    int f(int x){return k * dis[rnk[x]] + b;}
};
struct Nahida
{
    int l,r,val;
    line ln;
}tree[maxn << 2];
void adde(int u,int v,int w)
{
    e[++idx] = edge{v,w,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    siz[u] = 1,fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre)
            continue;
        dis[v] = dis[u] + e[i].w;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
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
    {
        int v = e[i].v;
        if (v != fa[u] && v != son[u])
            dfs2(v,v);
    }
}
inline int lca(int u,int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
inline void push_up(int rt){tree[rt].val = min({tree[ls].val,tree[rs].val,tree[rt].val});}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].val = inf;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,line ln,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        int lp = tree[rt].ln.f(l),rp = tree[rt].ln.f(r);
        int lq = ln.f(l),rq = ln.f(r);
        if (lq <= lp && rq <= rp)
        {
            tree[rt].ln = ln;
            tree[rt].val = min({tree[rt].val,lq,rq});
        }
        else if (lq < lp || rq < rp)
        {
            int mid = (l + r) >> 1;
            if (ln.f(mid) < tree[rt].ln.f(mid))
                swap(ln,tree[rt].ln);
            if (ln.f(l) < tree[rt].ln.f(l))
                upd(ql,qr,ln,ls);
            else
                upd(ql,qr,ln,rs);
            tree[rt].val = min(tree[rt].ln.f(l),tree[rt].ln.f(r));
            push_up(rt);
        }
    }
    else
    {
        int mid = (l + r) >> 1;
        if (ql <= mid)
            upd(ql,qr,ln,ls);
        if (qr > mid)
            upd(ql,qr,ln,rs);
        push_up(rt);
    }
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int lb = max(l,ql),rb = min(r,qr);
    int lp = tree[rt].ln.f(lb),rp = tree[rt].ln.f(rb);
    int mid = (l + r) >> 1,ret = min(lp,rp);
    if (ql <= mid)
        ret = min(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,rs));
    return ret;
}
void update(int u,int w,line ln)
{
    for (; top[u] != top[w]; u = fa[top[u]])
        upd(dfn[top[u]],dfn[u],ln);
    upd(dfn[w],dfn[u],ln);
}
int query(int u,int v)
{
    int ret = inf;
    for (; top[u] != top[v]; u = fa[top[u]])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        ret = min(ret,que(dfn[top[u]],dfn[u]));
    }
    return min(ret,que(dfn[v],dfn[u]));
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n,1);
    int op,s,t,a,b;
    while (m--)
    {
        scanf("%lld%lld%lld",&op,&s,&t);
        int w = lca(s,t);
        if (op == 1)
        {
            scanf("%lld%lld",&a,&b);
            update(s,w,line(-a,a * dis[s] + b));
            update(t,w,line(a,a * (dis[s] - 2 * dis[w]) + b));
        }
        else
            printf("%lld\n",min(query(s,w),query(t,w)));
    }
    return 0;
}