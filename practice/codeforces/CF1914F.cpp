#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,dp[maxn],siz[maxn];
vector<int> g[maxn];
void dfs(int u)
{
    siz[u] = 1;
    int son = 0;
    for (auto v : g[u])
    {
        dfs(v);
        siz[u] += siz[v];
        if (siz[son] < siz[v])
            son = v;
    }
    if (siz[son] <= (siz[u] - 1) >> 1)
        dp[u] = (siz[u] - 1) >> 1;
    else
        dp[u] = min((siz[u] - 1) >> 1,dp[son] + (siz[u] - siz[son] - 1));
}
void solve()
{
    scanf("%d",&n);
    fill(dp + 1,dp + n + 1,0);
    fill(siz + 1,siz + n + 1,0);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 2,x; i <= n; i++)
    {
        scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(1);
    printf("%d\n",dp[1]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}