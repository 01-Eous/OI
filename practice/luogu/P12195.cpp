#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,idx,tim;
int siz[maxn],son[maxn],s[maxn << 1],dep[maxn];
int head[maxn],dfn[maxn],rnk[maxn],fa[maxn],top[maxn];
struct{int v,nxt;}e[maxn << 1];
struct
{
    int val,tag;
    void tag_down(int x){val += x,tag += x;}
}tree[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
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
        if (int v = e[i].v; v != fa[u] && v != son[u])
            dfs2(v,v);
}
#define ls rt << 1
#define rs rt << 1 | 1
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    int &tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(tag);
    tree[rs].tag_down(tag);
    tag = 0;
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    int mid = (l + r) >> 1;
    push_down(rt);
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int mid = (l + r) >> 1,res = 0;
    push_down(rt);
    if (ql <= mid)
        res = max(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
#undef ls
#undef rs
void update(int u,int v,int x)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        upd(dfn[top[u]],dfn[u],x);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u,v);
    upd(dfn[v] + 1,dfn[u],x);
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
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    dfs1(1,0),dfs2(1,1);
    for (int i = 2; i <= m; i++)
    {
        update(s[i - 1],s[i],1);
        if (que(1,n) > 2)
        {
            for (int i = 1; i <= n; i++)
                puts("0");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        update(i,s[1],1);
        if (que(1,n) <= 2)
            puts("1");
        else
            puts("0");
        update(i,s[1],-1);
    }
    return 0;
}