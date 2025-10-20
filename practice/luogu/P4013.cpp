#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define toint(x,y) ((x - 1) * (n + m) + y)
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,m,s,t,idx = 1;
bool vis[2005];
int mp[25][45];
int head[2005],cur[2005],dis[2005];
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
    scanf("%d%d",&m,&n);
    s = 2001,t = 2002;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + i - 1; j++)
            scanf("%d",&mp[i][j]);
        
    for (int i = 1; i <= m; i++)
        add(s,toint(1,i),1,0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            add(toint(i,j),toint(i,j) + 1000,1,mp[i][j]);
            int x = i + 1,y = j;
            add(toint(i,j) + 1000,toint(x,y),1,0);
            y = j + 1;
            add(toint(i,j) + 1000,toint(x,y),1,0);
        }
    }
    for (int i = 1; i <= m + n - 1; i++)
    {
        add(toint(n,i),toint(n,i) + 1000,1,mp[n][i]);
        add(toint(n,i) + 1000,t,inf,0);
    }
    int ans = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf) * dis[t];
    }
    printf("%d\n",ans);

    ans = 0,idx = 1;
    memset(head,0,sizeof(head));
    for (int i = 1; i <= m; i++)
        add(s,toint(1,i),1,0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            add(toint(i,j),toint(i,j) + 1000,inf,mp[i][j]);
            int x = i + 1,y = j;
            add(toint(i,j) + 1000,toint(x,y),1,0);
            y = j + 1;
            add(toint(i,j) + 1000,toint(x,y),1,0);
        }
    }
    for (int i = 1; i <= m + n - 1; i++)
    {
        add(toint(n,i),toint(n,i) + 1000,inf,mp[n][i]);
        add(toint(n,i) + 1000,t,inf,0);
    }
    while (spfa())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf) * dis[t];
    }
    printf("%d\n",ans);

    ans = 0,idx = 1;
    memset(head,0,sizeof(head));
    for (int i = 1; i <= m; i++)
        add(s,toint(1,i),1,0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m + i - 1; j++)
        {
            add(toint(i,j),toint(i,j) + 1000,inf,mp[i][j]);
            int x = i + 1,y = j;
            add(toint(i,j) + 1000,toint(x,y),inf,0);
            y = j + 1;
            add(toint(i,j) + 1000,toint(x,y),inf,0);
        }
    }
    for (int i = 1; i <= m + n - 1; i++)
    {
        add(toint(n,i),toint(n,i) + 1000,inf,mp[n][i]);
        add(toint(n,i) + 1000,t,inf,0);
    }
    while (spfa())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf) * dis[t];
    }
    printf("%d\n",ans);
    return 0;
}