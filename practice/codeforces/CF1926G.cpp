#include <bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n;
char s[maxn];
int dp[2][maxn];//0 -> 'S',1 -> 'P'
vector<int>g[maxn];
void dfs(int u,int fa)
{
    if (s[u] == 'S' || s[u] == 'C')
        dp[0][u] = 0;
    if (s[u] == 'P' || s[u] == 'C')
        dp[1][u] = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        if (s[u] == 'S' || s[u] == 'C')
            dp[0][u] += min(dp[0][v],dp[1][v] + 1);
        if (s[u] == 'P' || s[u] == 'C')
            dp[1][u] += min(dp[1][v],dp[0][v] + 1);
    }
}
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 2,x; i <= n; i++)
    {
        scanf("%d",&x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    scanf("%s",s + 1);
    fill(dp[0] + 1,dp[0] + n + 1,inf);
    fill(dp[1] + 1,dp[1] + n + 1,inf);
    dfs(1,0);
    printf("%d\n",min(dp[0][1],dp[1][1]));
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}