#include<bits/extc++.h>
#define int long long
#define son(rt,x) tree[rt].ch[x]
using namespace std;
const int maxn = 1e5 + 5;
int n,q,tim,cnt;
int val[maxn],fa[maxn],son[maxn];
int siz[maxn],top[maxn],dep[maxn];
int dfn[maxn],rnk[maxn],root[maxn];
vector<int> g[maxn];
struct Nahida{int val,ch[2];}tree[maxn * 50];
void dfs1(int u,int pre)
{
    fa[u] = pre,dep[u] = dep[pre] + 1;
    siz[u] = 1;
    for (auto v : g[u])
    {
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
    for (auto v : g[u])
        if (v != son[u] && v != fa[u])
            dfs2(v,v);
}
void upd(int rt,int ori,int x)
{
    for (int i = 30; i >= 0; i--)
    {
        tree[rt].val = tree[ori].val + 1;
        if (x & (1 << i))
        {
            if (!son(rt,1))
                son(rt,1) = ++cnt;
            son(rt,0) = son(ori,0);
            rt = son(rt,1),ori = son(ori,1);
        }
        else
        {
            if (!son(rt,0))
                son(rt,0) = ++cnt;
            son(rt,1) = son(ori,1);
            rt = son(rt,0),ori = son(ori,0);
        }
    }
    tree[rt].val = tree[ori].val + 1;
}
int que(int ql,int qr,int x)
{
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        bool dig = (x & (1 << i));
        if (tree[son(qr,!dig)].val - tree[son(ql,!dig)].val)
        {
            res += (1 << i);
            ql = son(ql,!dig),qr = son(qr,!dig);
        }
        else
            ql = son(ql,dig),qr = son(qr,dig);
    }
    return res;
}
int que1(int u,int x){return que(root[dfn[u] - 1],root[dfn[u] + siz[u] - 1],x);}// for subtree
int que2(int u,int v,int x)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        res = max(res,que(root[dfn[top[u]] - 1],root[dfn[u]],x));
        u = fa[top[u]];
    }
    if (dfn[u] > dfn[v])
        swap(u,v);
    return max(res,que(root[dfn[u] - 1],root[dfn[v]],x));
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    int op,u,v,x;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for (int i = 1; i <= n; i++)
    {
        root[i] = ++cnt;
        upd(root[i],root[i - 1],val[rnk[i]]);
    }
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> u >> x;
            cout << que1(u,x) << '\n';
        }
        else
        {
            cin >> u >> v >> x;
            cout << que2(u,v,x) << '\n';
        }
    }
    return 0;
}