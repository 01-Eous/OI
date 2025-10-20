#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,idx,odd;
bool vis[maxn];
int head[maxn],pre[maxn];
int cnt[maxn][2],dep[maxn];
struct edge{int v,w,nxt;}e[maxn << 2];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    vis[u] = 1;
    dep[u] = dep[fa] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (w == pre[u])
            continue;
        if (vis[v])
        {
            if (dep[v] > dep[u])
                continue;
            int tmp = (dep[u] - dep[v]) & 1;
            if (!tmp)
                odd++;
            cnt[u][tmp]++;
            cnt[v][tmp]--;
        }
        else
        {
            pre[v] = w;
            dfs(v,u);
            cnt[u][0] += cnt[v][0];
            cnt[u][1] += cnt[v][1];
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1,u,v; i <= m; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v,i),adde(v,u,i);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i,0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (pre[i] && cnt[i][0] == odd && !cnt[i][1])
            ans++;
    printf("%d",ans + (odd == 1));
    return 0;
}