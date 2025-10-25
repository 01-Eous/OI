#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define chkmin(x,y) x = min(x,y)
using namespace std;
const int maxn = 1e6 + 5;
int n,idx;
int head[maxn],dp[maxn][2];
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    int min1 = inf,min2 = inf,son = 0,sum = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        son++,dfs(v,u);
        int tmp = min(dp[v][0],dp[v][1]) + 1;
        sum += tmp;
        if (dp[v][1] - tmp <= min1)
        {
            min2 = min1;
            min1 = dp[v][1] - tmp;
        }
        else if (dp[v][1] - tmp < min2)
            min2 = dp[v][1] - tmp;
    }
    // 断 son 条边
    dp[u][0] = dp[u][1] = sum;
    // 断 son - 1 条边
    chkmin(dp[u][1],sum + min1);
    // 断 son - 2 条边
    chkmin(dp[u][0],sum + min1 + min2);
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
    dfs(1,0);
    cout << min(dp[1][0],dp[1][1]) << '\n';
    return 0;
}