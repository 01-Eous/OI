#include<bits/extc++.h>
#define int long long
using namespace std;
int n,pls;
vector<int>l,r,dp;
vector<vector<int>>g;
template<typename type>
inline void init(vector<type>&x)
{
    x.clear();
    x.resize(n + 5);
}
void dfs(int u,int fa)
{
    int _max = 0;
    for (int v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        _max = max(_max,dp[v]);
    }
    if (r[u] >= _max)
    {
        dp[u] = max(l[u],_max);
        return;
    }
    for (int v : g[u])
        if (v != fa)
            pls += max(0ll,dp[v] - r[u]);
    dp[u] = r[u];
}
inline void solve()
{
    cin >> n;
    init(l);
    init(r);
    init(dp);
    init(g);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pls = 0;
    dfs(1,-114514);
    cout << dp[1] + pls << '\n';
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