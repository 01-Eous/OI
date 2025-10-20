#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,ans;
int a[maxn],dp[maxn];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    vector<int> pend;
    dp[u] = a[u];
    ans = max(ans,a[u]);
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        ans = max(ans,a[u] + dp[v]);
        dp[u] = max(dp[u],dp[v]);
        pend.push_back(dp[v]);
    }
    sort(pend.begin(),pend.end(),greater<>());
    if (pend.size() >= 2)
    {
        int tmp = pend[0] + pend[1];
        ans = max(ans,tmp);
        for (int i = 2; i < pend.size() && pend[i] > 0; i++)
            tmp += pend[i];
        dp[u] = max(dp[u],a[u] + tmp);
    }
    if (pend.size() >= 3)
    {
        int tmp = pend[0] + pend[1] + pend[2];
        for (int i = 3; i < pend.size() && pend[i] > 0; i++)
            tmp += pend[i];
        ans = max(ans,a[u] + tmp);
    }
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        g[i].clear();
    }
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    fill(dp + 1,dp + n + 1,0);
    dfs(1,0);
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld\n",&t);
    while (t--)
        solve();
    return 0;
}