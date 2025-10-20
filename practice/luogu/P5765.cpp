#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 5e4 + 5;
int n;
int dp[maxn][6];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    for (int i = 1; i <= 4; i++)
        dp[u][i] = i;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        for (int i = 1; i <= 4; i++)
        {
            int tmp = inf;
            for (int j = 1; j <= 4; j++)
                if (i != j)
                    tmp = min(tmp,dp[v][j]);
            dp[u][i] += tmp;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout << min({dp[1][1],dp[1][2],dp[1][3],dp[1][4]});
    return 0;
}