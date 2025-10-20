#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
using namespace std;
const int maxn = 1e6 + 5;
int n;
int dfn1[maxn],dfn2[maxn],tim;
int w[maxn],dep[maxn],f[25][maxn];
vector<int>g[maxn],a[maxn];
class BIT
{
    public:
    int tree[maxn];
    void upd(int i,int x)
    {
        for (; i <= tim; i += lowbit(i))
            tree[i] += x;
    }
    int que(int i)
    {
        int ret = 0;
        for (; i; i -= lowbit(i))
            ret += tree[i];
        return ret;
    }
    int que(int l,int r){return que(r) - que(l - 1);}
}t1,t2;
inline void init()
{
    tim = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i].clear();
        g[i].clear();
    }
}
int lca(int u,int v)
{
    if (!u || !v)
        return f[0][u | v];
    if (u > v)
        swap(u,v);
    int k = __lg(v - u + 1);
    if (dep[f[k][u]] < dep[f[k][v - (1 << k) + 1]])
        return f[k][u];
    else
        return f[k][v - (1 << k) + 1];
}
void dfs(int u,int fa)
{
    dep[u] = dep[fa] + 1;
    dfn1[u] = ++tim;
    f[0][tim] = u;
    for (int v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        f[0][++tim] = u;
    }
    dfn2[u] = tim;
}
void solve()
{
    cin >> n;
    init();
    for (int i = 1,tmp; i <= n; i++)
    {
        cin >> tmp;
        a[tmp].push_back(i);
    }
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= tim; i++)
        {
            if (dep[f[k - 1][i]] < dep[f[k - 1][i + (1 << (k - 1))]])
                f[k][i] = f[k - 1][i];
            else
                f[k][i] = f[k - 1][i + (1 << (k - 1))];
        }
    }
    fill(t1.tree + 1,t1.tree + tim + 1,0);
    fill(t2.tree + 1,t2.tree + tim + 1,0);
    set<int>b;
    vector<int>ans;
    int cnt1 = 0,cnt2 = 0;
    for (int k = n; k; k--)
    {
        for (int i : a[k])
        {
            if (t1.que(dfn1[i],dfn2[i]) < cnt1 && t2.que(dfn1[i],dfn2[i]) == cnt2)
                ans.push_back(i);
        }
        for (int i : a[k])
        {
            if (t1.que(dfn1[i], dfn2[i]) < cnt1)
            {
                auto l = b.lower_bound(dfn1[i]), r = b.lower_bound(dfn2[i]);
                int tmp1 = 0, tmp2 = 0;
                if (l != b.begin())
                    tmp1 = lca(*b.begin(),*(--l));
                if (r != b.end())
                    tmp2 = lca(*r, *b.rbegin());
                int t = lca(dfn1[tmp1], dfn1[tmp2]);
                t2.upd(dfn1[t], 1);
                t2.upd(dfn1[i], 1);
                t2.upd(dfn1[lca(dfn1[t], dfn1[i])], -1);
                cnt2++;
            }
        }
        for (int i : a[k])
        {
            cnt1++;
            b.insert(dfn1[i]);
            t1.upd(dfn1[i], 1);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << ' ';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}