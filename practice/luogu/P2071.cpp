#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 1e4 + 5;
int n,s,t,idx = 1;
int head[maxn],cur[maxn],dis[maxn];
struct edge{int v,w,nxt;}e[maxn << 2];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(dis));
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
    scanf("%d",&n);
    s = n * 3 + 1,t = s + 1;
    for (int i = 1,u,v; i <= n * 2; i++)
    {
        scanf("%d%d",&u,&v);
        add(u,i + n,1),add(v,i + n,1);
    }
    for (int i = 1; i <= n; i++)
        add(s,i,2);
    for (int i = 1; i <= n * 2; i++)
        add(i + n,t,1);
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    printf("%d",ans);
    return 0;
}