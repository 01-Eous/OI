#include<bits/extc++.h>
using namespace std;
const int maxn = 1.6e4 + 5;
int n,ans = INT_MIN;
int dp[maxn];
vector<int>g[maxn];
void dfs(int u,int fa)
{
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        dp[u] += max(dp[v],0);
    }
    ans = max(ans,dp[u]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i];
    for (int i = 1,a,b; i < n; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout << ans;
    return 0;
}