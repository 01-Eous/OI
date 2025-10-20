#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n,idx;
bool a[maxn];
int head[maxn],dp[maxn][2];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    dp[u][a[u]] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        dp[u][1] = (dp[u][0] * dp[v][1] % mod + dp[u][1] * dp[v][0] % mod + dp[u][1] * dp[v][1] % mod) % mod;
        dp[u][0] = (dp[u][0] * dp[v][0] % mod + dp[u][0] * dp[v][1] % mod) % mod;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,x; i < n; i++)
        cin >> x,adde(i,x),adde(x,i);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0,-1);
    cout << dp[0][1];
    return 0;
}