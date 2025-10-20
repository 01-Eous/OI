#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,ans;
int dp[3005][6005],tmp[6005];
int c[3005],cnt[3005],siz[3005];
vector<int> g[3005];
void dfs(int u,int fa,int col)
{
    siz[u] = 1;
    dp[u][n + (c[u] == col ? 1 : -1)] = 1;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u,col);
        int b1 = min(cnt[col],siz[u]),b2 = min(cnt[col],siz[v]);
        for (int i = -b1; i <= b1; i++)
            tmp[n + i] = dp[u][n + i];
        for (int i = -b1; i <= b1; i++)
            for (int j = -b2; j <= b2; j++)
                dp[u][n + i + j] = (dp[u][n + i + j] + tmp[n + i] * dp[v][n + j]) % mod;
        siz[u] += siz[v];
    }
    for (int i = 1; i <= cnt[col]; i++)
        ans = (ans + dp[u][n + i]) % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        cnt[c[i]]++;
    }
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!cnt[i])
            continue;
        for (int u = 1; u <= n; u++)
            for (int j = -cnt[i]; j <= cnt[i]; j++)
                dp[u][n + j] = 0;
        dfs(1,0,i);
    }
    cout << ans;
    return 0;
}