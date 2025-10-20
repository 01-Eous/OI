#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 3e5 + 5;
int n,q,tim;
int dfn[maxn],ed[maxn],dep[maxn];
int tree[maxn << 2],u[maxn],v[maxn];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    dfn[u] = ++tim;
    dep[u] = dep[fa] + 1;
    for (auto v : g[u])
        if (v != fa)
            dfs(v,u);
    ed[u] = tim;
}
void push_up(int rt){tree[rt] = tree[ls] + tree[rs];}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int pos,int x,int l = 1,int r = tim,int rt = 1)
{
    if (l == r)
    {
        tree[rt] += x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = tim,int rt = 1)
{

    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que(ql,qr,mid + 1,r,rs);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs(1,0);
    build(1,tim,1);
    cin >> q;
    int op,x,y;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            upd(dfn[x],y);
        }
        else
        {
            if (dep[u[x]] > dep[v[x]])
                y = u[x];
            else
                y = v[x];
            int sum1 = que(dfn[y],ed[y]),sum2 = tree[1] - sum1;
            cout << abs(sum1 - sum2) << '\n';
        }
    }
    return 0;
}