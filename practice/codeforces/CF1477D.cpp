#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,m,cnt;
int p[maxn],q[maxn],in[maxn];
int bel[maxn],root[maxn],siz[maxn];
set<int> st,s[maxn];
vector<int> g[maxn],a[maxn];
void dfs1(int u,int fa) 
{
    for (auto v : st)
    {
        if (!s[u].count(v))
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for (auto v : g[u])
        if (v != fa)
            st.erase(v);
    for (auto v : g[u])
        if (v != fa)
            dfs1(v,u);
}
void dfs2(int u,int fa)
{
    if (!bel[u])
    {
        bool fl = 0;
        for (auto v : g[u])
        {
            if (!bel[v])
            {
                fl = 1;
                break;
            }
        }
        if (fl)
        {
            bel[u] = ++cnt;
            siz[bel[u]] = 1;
            root[bel[u]] = u;
            for (auto v : g[u])
            {
                if (!bel[v])
                {
                    bel[v] = bel[u];
                    siz[bel[u]]++;
                }
            }
        }
        else
        {
            for (auto v : g[u])
            {
                if (!bel[v])
                    continue;
                if (root[bel[v]] == v)
                {
                    bel[u] = bel[v];
                    siz[bel[v]]++;
                }
                else if (siz[bel[v]] > 2)
                {
                    bel[u] = ++cnt;
                    root[cnt] = u;
                    siz[bel[v]]--;
                    bel[v] = cnt;
                    siz[cnt] = 2;
                }
                else
                {
                    bel[u] = bel[v];
                    root[bel[v]] = v;
                    siz[bel[v]]++;
                }
            }
        }
    }
    for (auto v : g[u])
        if (v != fa)
            dfs2(v,u);
}
void solve()
{
    cin >> n >> m;
    st.clear();
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
        bel[i] = siz[i] = 0;
        q[i] = p[i] = in[i] = 0;
        g[i].clear(),s[i].clear(),a[i].clear();
    }
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
        in[u]++,in[v]++;
    }
    cnt = n;
    vector<int> vec;
    for (int i = 1; i <= n; i++)
        if (in[i] == n - 1)
            st.erase(i),vec.push_back(i);
    while (!vec.empty())
    {
        int u = vec.back();
        vec.pop_back();
        p[u] = q[u] = cnt--;
        for (auto v : s[u])
            if (--in[v] >= cnt - 1 && st.count(v))
                st.erase(v),vec.push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (st.count(i))
            st.erase(i),dfs1(i,0);
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!p[i] && !bel[i])
            dfs2(i,0);
    for (int i = 1; i <= n; i++)
        if (bel[i])
            a[bel[i]].push_back(i);
    int idx = 1;
    for (int i = 1; i <= cnt; i++)
    {
        q[root[i]] = idx;
        for (auto u : a[i])
        {
            if (u != root[i])
            {
                p[u] = idx;
                q[u] = ++idx;
            }
        }
        p[root[i]] = idx++;
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++)
        cout << q[i] << " \n"[i == n];
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