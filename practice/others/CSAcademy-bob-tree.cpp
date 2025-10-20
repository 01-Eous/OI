#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,q,idx,cnt;
pii qry[maxn];
int head[maxn],fa[maxn],son[maxn];
int siz[maxn],dep[maxn],top[maxn],ans[maxn];
stack<int> stk;
vector<pii> col[maxn],tree[maxn << 2],res[maxn];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    fa[u] = pre,dep[u] = dep[pre] + 1;
    siz[u] = 1;
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
    if (!son[u])
        return;
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
int dis(int u,int v){return dep[u] + dep[v] - (dep[lca(u,v)] << 1);}
void upd(int ql,int qr,const pii &x,int l = 1,int r = q,int rt = 1)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
        return tree[rt].push_back(x);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
}
void insert(int u,int col)
{
    if (res[col].empty())
    {
        res[col].push_back({u,u});
        stk.push(col);
        return;
    }
    int x = res[col].back().first;
    int y = res[col].back().second;
    int nx = x,ny = y,d = dis(x,y),tmp = dis(u,x);
    if (tmp > d)
        nx = u,ny = x,d = dis(u,x);
    tmp = dis(u,y);
    if (tmp > d)
        nx = u,ny = y;
    res[col].push_back({nx,ny});
    stk.push(col);
}
void calc(int l = 1,int r = q,int rt = 1)
{
    int osiz = stk.size();
    for (auto [u,col] : tree[rt])
        insert(u,col);
    if (l == r)
    {
        int tmp = qry[l].first;
        if (tmp)
            ans[qry[l].second] = dis(res[tmp].back().first,res[tmp].back().second);
    }
    else
    {
        int mid = (l + r) >> 1;
        calc(l,mid,ls);
        calc(mid + 1,r,rs);
    }
    while (stk.size() > osiz)
    {
        res[stk.top()].pop_back();
        stk.pop();
    }
}
signed main()
{
    scanf("%d",&n);
    int op,u,v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        col[i].push_back({1,u});
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs1(1,0),dfs2(1,1);
    scanf("%d",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d",&op,&u);
        if (op == 1)
        {
            scanf("%d",&v);
            col[u].push_back({i,v});
        }
        else
            qry[i] = {u,++cnt};
    }
    for (int i = 1; i <= n; i++)
    {
        col[i].push_back({q + 1,0});
        for (int j = 1; j < col[i].size(); j++)
            upd(col[i][j - 1].first,col[i][j].first - 1,{i,col[i][j - 1].second});
    }
    calc();
    for (int i = 1; i <= cnt; i++)
        printf("%d\n",ans[i]);
    return 0;
}