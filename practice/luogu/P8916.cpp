#include<bits/extc++.h>
using namespace std;
int n,idx;
int head[305],a[305];
int dp[305][2][305][305];
struct{int v,nxt;}e[605];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[u][0][i][j] = (i + 1) * a[u];
            dp[u][1][i][j] = (j + 1) * a[u];
        }
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[u][0][j][k] += max(dp[v][0][j + 1][k],dp[v][1][j][k]);
                dp[u][1][j][k] += max(dp[v][0][j][k],dp[v][1][j][k + 1]);
            }
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
        adde(u,v),adde(v,u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1,0);
    cout << max(dp[1][0][0][0],dp[1][1][0][0]) << '\n';
    return 0;
}