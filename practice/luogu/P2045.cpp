#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
const int maxn = 1e5 + 5;
const int dir[2][2] = {1,0,0,1};
int n,m,k;
int s,t,idx = 1;
bool vis[5005];
int head[5005],cur[5005],dis[5005];
struct edge{int v,w,c,nxt;}e[maxn];
int id(int x,int y){return (x - 1) * n + y;}
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,~0x3f,sizeof(int) * (m * 2 + 5));
    memset(vis,0,sizeof(bool) * (m * 2 + 5));
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
            if (e[i].w > 0 && dis[v] < dis[u] + e[i].c)
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
        if (!vis[v] && e[i].w > 0 && dis[v] == dis[u] + e[i].c)
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
    scanf("%d%d",&n,&k);
    m = n * n;
    s = m << 1 | 1,t = s + 1;
    add(s,id(1,1),k,0);
    add(id(n,n) + m,t,k,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int _ = 0; _ < 2; _++)
            {
                int x = i + dir[_][0],y = j + dir[_][1];
                if (1 <= x && x <= n && 1 <= y && y <= n)
                    add(id(i,j) + m,id(x,y),inf,0);
            }
        }
    }
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&x);
            add(id(i,j),id(i,j) + m,1,x);
            add(id(i,j),id(i,j) + m,inf,0);
        }
    }
    int ans = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (m * 2 + 5));
        int tmp = dfs(s,inf);
        ans += dis[t] * tmp;
    }
    printf("%d",ans);
    return 0;
}