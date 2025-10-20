#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define id(x,y) ((x) * (m + 1) + (y))
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,m,a,b,s,t,idx = 1;
bool vis[405];
int head[405],cur[405],dis[405];
struct edge{int v,w,c,nxt;}e[100005];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,~0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].w && dis[v] < dis[u] + e[i].c)
            {
                dis[v] = dis[u] + e[i].c;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[t] != ~inf;
}
int dfs(int u,int maxf)
{
    if (u == t)
        return maxf;
    vis[u] = 1;
    int res = 0;
    for (int i = cur[u]; i && maxf; i = e[i].nxt)
    {
        cur[u] = i;
        int v = e[i].v;
        if (e[i].w && !vis[v] && dis[v] == dis[u] + e[i].c)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    vis[u] = 0;
    if (!res)
        dis[u] = ~inf;
    return res;
}
signed main()
{
    scanf("%d%d%d%d",&a,&b,&n,&m);
    s = 401,t = s + 1;
    int x,y,w;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&x);
            add(id(i,j),id(i,j + 1),1,x);
            add(id(i,j),id(i,j + 1),inf,0);
        }
    }
    for (int j = 0; j <= m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            add(id(i,j),id(i + 1,j),1,x);
            add(id(i,j),id(i + 1,j),inf,0);
        }
    }
    while (a--)
    {
        scanf("%d%d%d",&w,&x,&y);
        add(s,id(x,y),w,0);
    }
    while (b--)
    {
        scanf("%d%d%d",&w,&x,&y);
        add(id(x,y),t,w,0);
    }
    int ans = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(head));
        ans += dis[t] * dfs(s,inf);
    }
    printf("%d",ans);
    return 0;
}