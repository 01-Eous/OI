#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e4 + 5;
int n,ans;
bool vis[maxn];
int w[maxn],head[maxn],idx;
int _min,ssiz,rt;
struct edge{int v,nxt;}e[maxn << 1];
struct line
{
    int k,b;
    line(int k = 0,int b = -inf):k(k),b(b){};
    int f(int x){return k * x + b;}
    friend bool operator==(const line &x,const line &y){return x.k == y.k && x.b == y.b;}
};
struct Nahida
{
    line ln;
    int l,r;
}tree[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = edge{v,head[u]};
    head[u] = idx;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].ln = line();
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void clear(int rt = 1)
{
    if (tree[rt].ln == line())
        return;
    tree[rt].ln = line();
    if (tree[rt].l != tree[rt].r)
        clear(ls),clear(rs);
}
void upd(line ln,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    int lp = tree[rt].ln.f(l),rp = tree[rt].ln.f(r);
    int lq = ln.f(l),rq = ln.f(r);
    if (lq >= lp && rq >= rp)
        tree[rt].ln = ln;
    else if (lq >= lp || rq >= rp)
    {
        int mid = (l + r) >> 1;
        if (ln.f(mid) > tree[rt].ln.f(mid))
            swap(ln,tree[rt].ln);
        if (ln.f(l) > tree[rt].ln.f(l))
            upd(ln,ls);
        else
            upd(ln,rs);
    }
}
int que(int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
        return tree[rt].ln.f(x);
    int mid = (l + r) << 1,ret = tree[rt].ln.f(x);
    if (x <= mid)
        ret = max(ret,que(x,ls));
    else
        ret = max(ret,que(x,rs));
    return ret;
}
void dfs1(int u,int fa = 0)
{
    ssiz++;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
    }
}
int dfs2(int u,int fa = 0)
{
    int siz = 1,_max = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        int tmp = dfs2(v,u);
        siz += tmp;
        _max = max(_max,tmp);
    }
    _max = max(_max,ssiz - siz);
    if (_max < _min)
    {
        _min = _max;
        rt = u;
    }
    return siz;
}
void dfs3(int u,int pos,int k,int b,int fa)
{
    ans = max(ans,que(pos) + b);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v != fa && !vis[v])
            dfs3(v,pos + 1,w[v] + k,b + w[v] + k,u);
    }
}
void dfs4(int u,int pos,int k,int b,int fa)
{
    upd(line(k,b));
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v != fa && !vis[v])
            dfs4(v,pos + 1,w[v] + k,b + pos * w[v],u);
    }
}
void dfs(int u)
{
    _min = inf,ssiz = 0;
    dfs1(u);
    dfs2(u);
    vis[u = rt] = 1;
    clear();
    upd(line(0,0));
    vector<int>to;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        to.push_back(v);
        dfs3(v,2,w[u] + w[v],w[u] * 2 + w[v],0);
        dfs4(v,2,w[v],w[v],0);
    }
    ans = max(ans,que(1) + w[u]);
    clear();
    reverse(to.begin(),to.end());
    for (auto v : to)
    {
        dfs3(v,2,w[u] + w[v],w[u] * 2 + w[v],0);
        dfs4(v,2,w[v],w[v],0);
    }
    for (auto v : to)
        dfs(v);
}
void solve()
{
    scanf("%lld",&n);
    fill(vis + 1,vis + n + 1,0);
    fill(head + 1,head + n + 1,0);
    idx = rt = ssiz = 0;
    ans = -inf;
    build(1,n,1);
    for (int i = 1; i <= n; i++)
        scanf("%lld",w + i);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    dfs(1);
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}