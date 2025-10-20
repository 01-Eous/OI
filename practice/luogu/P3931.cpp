#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,rt,idx;
int head[maxn],dp[maxn];
struct edge{int v,w,nxt;}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    bool fl = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        fl = 1,dfs(v,u);
        dp[u] += min(dp[v],e[i].w);
    }
    if (!fl)
        dp[u] = inf;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> rt;
    for (int i = 1,u,v,w; i < n; i++)
    {
        cin >> u >> v >> w;
        adde(u,v,w),adde(v,u,w);
    }
    dfs(rt,0);
    cout << dp[rt];
    return 0;
}