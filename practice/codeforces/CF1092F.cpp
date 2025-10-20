#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,ans;
int a[maxn],siz[maxn];
int dp1[maxn],dp2[maxn];
vector<int> g[maxn];
void dfs1(int u,int fa)
{
    siz[u] = a[u];
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        dp1[u] += dp1[v] + siz[v];
    }
}
void dfs2(int u,int fa)
{
    ans = max(ans,dp2[u]);
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dp2[v] = dp2[u] - siz[v] + siz[1] - siz[v];
        dfs2(v,u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    ans = dp2[1] = dp1[1];
    dfs2(1,0);
    cout << ans;
    return 0;
}