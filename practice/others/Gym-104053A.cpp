#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define chkmin(x,y) x = min(x,y)
using namespace std;
int n;
int a[2005],t[2005],siz[2005];
int dp[2005][2005][2],cur[2005][2],tmp1[2005],tmp2[2005];
vector<int> g[2005];
void dfs(int u,int fa)
{
    int sum = siz[u] = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        sum += siz[v];
    }
    if (!sum)
    {
        siz[u] = 1;
        dp[u][0][0] = a[u];
        dp[u][0][1] = dp[u][1][0] = dp[u][1][1] = 0;
        return;
    }
    for (int i = 0; i <= sum; i++)
        dp[u][i][0] = dp[u][i][1] = tmp1[i] = inf;
    dp[u][0][0] = dp[u][0][1] = tmp1[0] = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        for (int i = 0; i <= siz[u] + siz[v]; i++)
            cur[i][0] = cur[i][1] = tmp2[i] = inf;
        for (int i = 0; i <= siz[u]; i++)
        {
            for (int j = 0; j <= siz[v]; j++)
            {
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2 - x; y++)
                        chkmin(cur[i + j][x + y],dp[u][i][x] + dp[v][j][y]);
                chkmin(tmp2[i + j],tmp1[i] + dp[v][j][1]);
            }
        }
        siz[u] += siz[v];
        for (int i = 0; i <= siz[u]; i++)
        {
            tmp1[i] = tmp2[i];
            dp[u][i][0] = cur[i][0];
            dp[u][i][1] = cur[i][1];
        }
    }
    for (int i = 0; i <= siz[u]; i++)
    {
        chkmin(dp[u][i][0],tmp1[i] + a[u]);
        chkmin(dp[u][i][1],dp[u][i][0]);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans = inf;
    for (int i = 0; i <= siz[1]; i++)
        chkmin(ans,dp[1][i][1] + t[i]);
    cout << ans << '\n';
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