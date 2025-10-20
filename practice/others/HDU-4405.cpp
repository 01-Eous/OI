#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
typedef double ld;
int n,m;
void solve()
{
    vector<ld> dp(n + 10);
    vector<bool> vis(n + 5);
    vector<vector<int>> g(n + 5);
    int x,y;
    while (m--)
    {
        cin >> x >> y;
        g[y].push_back(x);
    }
    for (auto v : g[n])
        vis[v] = 1;
    for (int u = n - 1; u >= 0; u--)
    {
        if (!vis[u])
        {
            dp[u] = 1;
            for (int i = 1; i <= 6; i++)
                dp[u] += dp[u + i] / 6;
        }
        for (auto v : g[u])
        {
            dp[v] = dp[u];
            vis[v] = 1;
        }
    }
    cout << dp[0] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(4);
    while (cin >> n >> m,n || m)
        solve();
    return 0;
}