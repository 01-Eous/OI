#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using ld = double;
int n,m,idx;
int head[105],siz[105];
struct edge{int v,nxt;}e[205];
struct node
{
    int val,wei;
    node(int val = 0,int wei = inf):val(val),wei(wei){}
    friend node operator+(const node &x,const node &y)
    {return (node){x.val + y.val,x.wei + y.wei};}
    friend bool operator<(const node &x,const node &y)
    {return (ld)x.val / x.wei < (ld)y.val / y.wei;}
}dp[105][105],a[105];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    siz[u] = 1;
    dp[u][1] = a[u];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        for (int j = n; j > 1; j--)
            for (int k = 1; k < j; k++)
                dp[u][j] = max(dp[u][j],dp[u][k] + dp[v][j - k]);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].val;
    for (int i = 1; i <= n; i++)
        cin >> a[i].wei;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    ld ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = m; j <= n; j++)
            ans = max(ans,(ld)dp[i][j].val / dp[i][j].wei);
    cout << fixed << setprecision(2) << ans;
    return 0;
}