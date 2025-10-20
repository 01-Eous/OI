#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
int n,m,s,t,idx = 1;
int head[205],cur[205],dis[205];
struct edge{int v,w,nxt;}e[100005];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * ((n << 1) + 5));
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
    for (int i = cur[u]; i; i = e[i].nxt)
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
    scanf("%d%d%d%d",&n,&m,&s,&t);
    t += n;
    int u,v;
    while (m--)
    {
        scanf("%d%d",&u,&v);
        add(u,v + n,inf);// 从 u 的出点连一条边到 v 的入点
        add(v,u + n,inf);// 从 v 的出点连一条边到 u 的入点
    }
    for (int i = 1; i <= n; i++)
        add(i + n,i,1);// 从 i 的入点连一条边到 i 的出点
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        ans += dfs(s,inf);
    }
    printf("%d",ans);
    return 0;
}