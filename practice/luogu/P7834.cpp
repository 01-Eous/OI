#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 5e5 + 5;
typedef pair<int,int> pii;
int n,m,q,tim,tot,nn,cnt;
int a[maxn],num[maxn],val[maxn];
int dfn[maxn],rnk[maxn],en[maxn];
int fa[maxn],anc[maxn][25],root[maxn];
vector<int> g[maxn];
struct edge{int u,v,w;}e[maxn];
struct Nahida{int lson,rson,val;}tree[maxn * 50];
bool cmp(const edge &x,const edge &y){return x.w < y.w;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void kruskal()
{
    sort(e + 1,e + m + 1,cmp);
    iota(fa + 1,fa + n + 1,1);
    tot = n;
    for (int i = 1; i <= m; i++)
    {
        auto [u,v,w] = e[i];
        u = find(u),v = find(v);
        if (u == v)
            continue;
        val[++tot] = w;
        fa[u] = fa[v] = fa[tot] = tot;
        g[tot].push_back(u);
        g[tot].push_back(v);
    }
}
void dfs(int u)
{
    dfn[u] = ++tim;
    rnk[tim] = u;
    for (auto v : g[u])
    {
        anc[v][0] = u;
        dfs(v);
    }
    en[u] = tim;
}
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    tree[cnt].val++;
    return cnt;
}
int build(int l,int r)
{
    int rt = ++cnt;
    tree[rt].val = 0;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    ls = build(l,mid);
    rs = build(mid + 1,r);
    return rt;
}
int upd(int pos,int l,int r,int rt)
{
    if (!pos)
        return rt;
    rt = clone(rt);
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,l,mid,ls);
    else
        rs = upd(pos,mid + 1,r,rs);
    return rt;
}
int que(int ql,int qr,int l,int r,int k)
{
    if (l == r)
        return l;
    if (tree[qr].val - tree[ql].val < k)
        return 0;
    int mid = (l + r) >> 1;
    int tmp = tree[tree[qr].rson].val - tree[tree[ql].rson].val;
    if (tmp < k)
        return que(tree[ql].lson,tree[qr].lson,l,mid,k - tmp);
    else
        return que(tree[ql].rson,tree[qr].rson,mid + 1,r,k);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num + 1,num + n + 1);
    nn = unique(num + 1,num + n + 1) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1,num + nn + 1,a[i]) - num;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    kruskal();
    for (int i = 1; i <= tot; i++)
        if (find(i) == i)
            dfs(i);
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= tot; u++)
            anc[u][i] = anc[anc[u][i - 1]][i - 1];
    root[0] = build(1,nn);
    for (int i = 1; i <= tot; i++)
        root[i] = upd(a[rnk[i]],1,nn,root[i - 1]);
    int u,x,k,lst = 0;
    while (q--)
    {
        cin >> u >> x >> k;
        u = (u ^ lst) % n + 1;
        x = x ^ lst;
        k = (k ^ lst) % n + 1;
        for (int i = 20; i >= 0; i--)
            if (anc[u][i] && val[anc[u][i]] <= x)
                u = anc[u][i];
        lst = num[que(root[dfn[u] - 1],root[en[u]],1,nn,k)];
        if (lst)
            cout << lst << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}