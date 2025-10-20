#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,m,L,R,ans = -inf;
bool vis[maxn];
int dep[maxn],dis[maxn];
int c[maxn],head[maxn],idx;
int siz[maxn],wei[maxn],ssiz,rt;
vector<int>sub;
struct edge{int v,w,nxt;}e[maxn << 1];
struct 线段树
{
    struct Nahida{int l,r,val;}tree[maxn << 2];
    stack<int>nd;
    void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);nd.push(rt);}
    void build(int l,int r,int rt)
    {
        tree[rt].l = l,tree[rt].r = r;
        tree[rt].val = -inf;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l,mid,ls);
        build(mid + 1,r,rs);
    }
    void upd(int pos,int x,int rt = 1)
    {
        int l = tree[rt].l,r = tree[rt].r;
        if (l == r)
        {
            tree[rt].val = max(tree[rt].val,x);
            return nd.push(rt);
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(pos,x,ls);
        else
            upd(pos,x,rs);
        push_up(rt);
    }
    int que(int ql,int qr,int rt = 1)
    {
        if (ql > qr)
            return -inf;
        int l = tree[rt].l,r = tree[rt].r;
        if (ql <= l && r <= qr)
            return tree[rt].val;
        int mid = (l + r) >> 1,ret = -inf;
        if (ql <= mid)
            ret = max(ret,que(ql,qr,ls));
        if (qr > mid)
            ret = max(ret,que(ql,qr,rs));
        return ret;
    }
    void clear()
    {
        while (!nd.empty())
        {
            tree[nd.top()].val = -inf;
            nd.pop();
        }
    }
}t1,t2;
inline void read(int &x)
{
    int f = 1;x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline void adde(int u,int v,int w)
{
    e[++idx] = edge{v,w,head[u]};
    head[u] = idx;
}
void dfs1(int u,int fa)
{
    siz[u] = 1,wei[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int fa,int pre)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (v == fa || vis[v])
            continue;
        dep[v] = dep[u] + 1;
        dis[v] = dis[u] + (w != pre) * c[w];
        dfs2(v,u,w);
    }
}
void dfs3(int u,int fa)
{
    sub.push_back(u);
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs3(v,u);
}
void dfs(int u)
{
    vis[u] = 1;
    dis[u] = dep[u] = 0;
    vector<pii>son;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (vis[v])
            continue;
        dep[v] = 1;
        dis[v] = c[w];
        dfs2(v,u,w);
        son.push_back({w,v});
    }
    sort(son.begin(),son.end());
    t1.upd(0,0);
    vector<int>tmp;
    for (int i = 0; i < son.size(); i++)
    {
        if (i && son[i].first != son[i - 1].first)
        {
            t2.clear();
            for (int j : tmp)
                t1.upd(dep[j],dis[j]);
            tmp.clear();
        }
        int v = son[i].second;
        sub.clear();
        dfs3(v,u);
        for (auto j : sub)
        {
            int depth = dep[j];
            if (depth > R)
                continue;
            ans = max(ans,t1.que(max(0ll,L - depth),R - depth) + dis[j]);
            ans = max(ans,t2.que(max(0ll,L - depth),R - depth) + dis[j] - c[son[i].first]);
        }
        for (auto j : sub)
        {
            tmp.push_back(j);
            t2.upd(dep[j],dis[j]);
        }
    }
    t1.clear(),t2.clear();
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        wei[rt = 0] = inf;
        ssiz = siz[v];
        dfs1(v,u);
        dfs(rt);
    }
}
signed main()
{
    read(n),read(m),read(L),read(R);
    t1.build(0,n,1);
    t2.build(0,n,1);
    for (int i = 1; i <= m; i++)
        read(c[i]);
    for (int i = 1,u,v,w; i < n; i++)
    {
        read(u),read(v),read(w);
        adde(u,v,w);
        adde(v,u,w);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    printf("%lld",ans);
    return 0;
}