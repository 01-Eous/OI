#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,m,matt,ans;
int bel[maxn],c[maxn],l[maxn],siz[maxn],sum[maxn];
vector<int>g[maxn];
struct Nahida{int lson,rson,dis,val,fa;}tree[maxn];
int merge(int rt,int x)
{
    if (!rt || !x)
        return rt | x;
    if (tree[rt].val < tree[x].val)
        swap(rt,x);
    rs = merge(rs,x);
    if (tree[ls].dis < tree[rs].dis)
        swap(ls,rs);
    tree[ls].fa = tree[rs].fa = tree[rt].fa = rt;
    tree[rt].dis = tree[rs].dis + 1;
    return rt;
}
int pop(int rt)
{
    int lson = ls,rson = rs;
    tree[lson].fa = lson;
    tree[rson].fa = rson;
    ls = rs = tree[rt].dis = 0;
    return merge(lson,rson);
}
void dfs(int u)
{
    siz[u] = 1;
    sum[u] = c[u];
    for (auto v : g[u])
    {
        dfs(v);
        bel[u] = merge(bel[u],bel[v]);
        siz[u] += siz[v];
        sum[u] += sum[v];
    }
    while (sum[u] > m)
    {
        siz[u]--;
        sum[u] -= tree[bel[u]].val;
        bel[u] = pop(bel[u]);
    }
    ans = max(ans,siz[u] * l[u]);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1,fa; i <= n; i++)
    {
        scanf("%lld%lld%lld",&fa,c + i,l + i);
        if (fa)
            g[fa].push_back(i);
        else
            matt = i;
        bel[i] = i;
        tree[i].val = c[i];
    }
    dfs(matt);
    printf("%lld",ans);
    return 0;
}