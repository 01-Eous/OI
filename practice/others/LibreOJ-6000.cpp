#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s,t,flow,idx = 1;
int head[105],cur[105],dis[105];
struct edge{int v,w,nxt;}e[30005];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void ins(int u,int v,int w){adde(u,v,w),adde(v,u,0);}
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
    scanf("%d%d",&n,&m);
    s = 0,t = n + 1;
    for (int i = 1; i <= m; i++)
        ins(s,i,1);
    for (int i = m + 1; i <= n; i++)
        ins(i,t,1);
    int u,v;
    while (scanf("%d%d",&u,&v) != EOF)
        ins(u,v,1);
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        flow += dfs(s,inf);
    }
    printf("%d",flow);
    return 0;
}