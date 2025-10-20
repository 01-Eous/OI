#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e4 + 5;
int n,m;
int dp[maxn][16];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    for (int i = 1; i <= m; i++)
        dp[u][i] = i;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        for (int i = 1; i <= m; i++)
        {
            int _min = inf;
            for (int j = 1; j <= m; j++)
                if (i != j)
                    _min = min(_min,dp[v][j]);
            dp[u][i] += _min;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = __lg(n) + 1;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int _min = inf;
    for (int i = 1; i <= m; i++)
        _min = min(_min,dp[1][i]);
    cout << _min;
    return 0;
}