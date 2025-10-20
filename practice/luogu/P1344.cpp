#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 114514;
int n,m;
int s,t,idx = 1;
bool vis[35];
int head[35],cur[35],dis[35];
struct edge{int v,w,nxt;}e[maxn];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].w && dis[v] == inf)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[t] != inf;
}
int dfs(int u,int maxf)
{
    if (u == t)
        return maxf;
    int res = 0;
    for (int i = cur[u]; i && maxf; i = e[i].nxt)
    {
        cur[u] = i;
        int v = e[i].v;
        if (e[i].w && dis[v] == dis[u] + 1)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    if (!res)
        dis[u] = inf;
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    s = 1,t = n;
    int u,v,w;
    while (m--)
    {
        cin >> u >> v >> w;
        add(u,v,w * maxn + 1);
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        ans += dfs(s,inf);
    }
    printf("%lld %lld",ans / maxn,ans % maxn);
    return 0;
}