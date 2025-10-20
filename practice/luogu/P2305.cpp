#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,t,idx,tim,cnt;
int head[maxn],s[maxn],p[maxn],q[maxn],len[maxn];
int dfn[maxn],rnk[maxn],dis[maxn],dp[maxn],root[maxn],k[maxn],b[maxn];
struct edge{int v,nxt;}e[maxn << 1];
struct Nahida
{
    int x;
    int lson,rson;
}tree[maxn << 5];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int f(int i,int x){return k[i] * x + b[i];}
#define ls tree[rt].lson
#define rs tree[rt].rson
void upd_lc(int x,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (!tree[rt].x)
    {
        tree[rt].x = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (f(x,mid) < f(tree[rt].x,mid))
        swap(x,tree[rt].x);
    if (f(x,l) < f(tree[rt].x,l))
        upd_lc(x,l,mid,ls);
    if (f(x,r) < f(tree[rt].x,r))
        upd_lc(x,mid + 1,r,rs);
}
int que_lc(int x,int l,int r,int rt)
{
    if (!rt)
        return inf;
    int res = f(tree[rt].x,x);
    if (l == r)
        return res;
    int mid = (l + r) >> 1;
    if (x <= mid)
        res = min(res,que_lc(x,l,mid,ls));
    else
        res = min(res,que_lc(x,mid + 1,r,rs));
    return res;
}
#undef ls
#undef rs
#define ls rt << 1
#define rs rt << 1 | 1
void upd(int pos,int x,int l = 1,int r = n,int rt = 1)
{
    upd_lc(x,0,1e6,root[rt]);
    if (l == r)
        return; 
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
}
int que(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return que_lc(x,0,1e6,root[rt]);
    int mid = (l + r) >> 1,res = inf;
    if (ql <= mid)
        res = min(res,que(ql,qr,x,l,mid,ls));
    if (qr > mid)
        res = min(res,que(ql,qr,x,mid + 1,r,rs));
    return res;
}
#undef ls
#undef rs
void dfs1(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
        dfs1(e[i].v);
    dfn[u] = ++tim;
}
void dfs2(int u)
{
    k[u] = -dis[tim],b[u] = dp[u];
    rnk[tim] = u,upd(dfn[u],u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        tim++,dis[tim] = dis[tim - 1] + s[v];
        int anc = rnk[lower_bound(dis,dis + tim,dis[tim] - len[v]) - dis];
        dp[v] = que(dfn[v],dfn[anc],p[v]) + dis[tim] * p[v] + q[v];
        dfs2(v),--tim;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 2,fa; i <= n; i++)
        cin >> fa >> s[i] >> p[i] >> q[i] >> len[i],adde(fa,i);
    dfs1(1),tim = 0,dfs2(1);
    for (int i = 2; i <= n; i++)
        cout << dp[i] << '\n';
    return 0;
}