#include<bits/extc++.h>
using namespace std;
int n;
bool vis[20];
int dp[20][20][1 << 16 | 5];
vector<int>g[20];
string s[20],w[20];
int dfs(int u,int len)
{
    int p = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            p |= 1 << (i - 1);
    if (dp[u][len][p])
        return dp[u][len][p];
    int ret = len;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            ret = max(ret,dfs(v,len + 1));
            vis[v] = 0;
        }
    }
    return dp[u][len][p] = ret;
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> w[i];
        g[0].push_back(i);
        for (int j = 1; j < i; j++)
        {
            if (s[i] == s[j] || w[i] == w[j])
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    fill(vis,vis + n + 1,0);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < (1 << n); k++)
                dp[i][j][k] = 0;
    cout << n - dfs(0,0) << '\n';
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