#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
int n,m,s,t,idx = 1;
int head[505],cur[505],dis[505];
struct edge{int v,w,nxt;}e[100005];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n + m + 5));
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
    s = n + m + 1,t = s + 1;
    int x = 0,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        add(s,i,x),ans += x;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&x);
        add(i + n,t,x);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            add(i,j + n,1);
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + m + 5));
        ans -= dfs(s,inf);
    }
    if (ans)
        return printf("0"),0;
    puts("1");
    for (int u = 1; u <= n; u++)
    {
        for (int i = head[u]; i; i = e[i].nxt)
            if (int v = e[i].v; v != s && e[i ^ 1].w)
                printf("%d ",v - n);
        putchar('\n');
    }
    return 0;
}