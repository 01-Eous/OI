#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using i3 = array<int,3>;
const int maxn = 1 << 18 | 5;
int n,m,a,b,cnt,lim;
int g[75][75],bel[75],dp[75][maxn];
bool vis1[75],vis2[75],vis[75][maxn];
int dfs1(int u)
{
    vis1[u] = 1;
    int siz = 1;
    for (int v = 1; v <= n; v++)
        if (!vis1[v] && g[u][v] == a)
            siz += dfs1(v);
    return siz;
}
void dfs2(int u,int id)
{
    bel[u] = id,vis2[u] = 1;
    for (int v = 1; v <= n; v++)
        if (!vis2[v] && g[u][v] == a)
            dfs2(v,id);
}
void dij()
{
    memset(dp,0x3f,sizeof(dp));
    memset(vis,0,sizeof(vis));
    priority_queue<i3,vector<i3>,greater<>> q;
    dp[1][0] = 0;
    q.push({0,1,0});
    while (!q.empty())
    {
        int u = q.top()[1];
        int s = q.top()[2];
        q.pop();
        if (vis[u][s])
            continue;
        vis[u][s] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (g[u][v] == inf)
                continue;
            int ns = s;
            if (g[u][v] == b)
            {
                if (bel[u] == bel[v] || (bel[v] < lim && ((s >> bel[v]) & 1)))
                    continue;
                if (bel[u] < lim)
                    ns |= 1 << bel[u];
            }
            if (dp[v][ns] > dp[u][s] + g[u][v])
            {
                dp[v][ns] = dp[u][s] + g[u][v];
                q.push({dp[v][ns],v,ns});
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    memset(g,0x3f,sizeof(g));
    int u,v,w;
    while (m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        g[u][v] = min(g[u][v],w);
        g[v][u] = min(g[v][u],w);
    }
    for (int i = 1; i <= n; i++)
        if (!vis1[i])
            if (dfs1(i) >= 4)
                dfs2(i,cnt++);
    lim = cnt;
    memset(vis1,0,sizeof(vis1));
    for (int i = 1; i <= n; i++)
        if (!vis1[i])
            if (dfs1(i) < 4)
                dfs2(i,cnt++);
    dij();
    for (int i = 1; i <= n; i++)
        printf("%d ",*min_element(dp[i],dp[i] + (1 << lim)));
    return 0;
}