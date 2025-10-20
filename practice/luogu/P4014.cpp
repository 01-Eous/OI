#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,s,t,val,idx = 1;
bool vis[105];
int head[105],cur[105],dis[105];
struct edge{int v,w,c,nxt;}e[6005],ori[6005];
void adde(int u,int v,int w,int c)
{
    idx++;
    e[idx] = {v,w,c,head[u]};
    ori[idx] = e[idx];
    head[u] = idx;
}
bool cmp1(int x,int y){return x < y;}
bool cmp2(int x,int y){return x > y;}
bool spfa(bool (*cmp)(int x,int y))
{
    memset(dis,val,sizeof(int) * ((n << 1) + 5));
    memset(vis,0,sizeof(bool) * ((n << 1) + 5));
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
            if (e[i].w && cmp(dis[u] + e[i].c,dis[v]))
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
    return dis[t] != val;
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
        if (e[i].w && !vis[v] &&dis[v] == dis[u] + e[i].c)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    if (!res)
        dis[u] = val;
    return res;
}
signed main()
{
    scanf("%d",&n);
    s = n << 1 | 1,t = s + 1;
    for (int i = 1; i <= n; i++)
        add(s,i,1,0);
    for (int i = n + 1; i <= (n << 1); i++)
        add(i,t,1,0);
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&x);
            add(i,j + n,1,x);
        }
    }
    int ans1 = 0,ans2 = 0;
    val = inf;
    while (spfa(cmp1))
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        ans1 += dis[t] * dfs(s,inf);
    }
    memcpy(e,ori,sizeof(edge) * (idx + 5));
    val = ~inf;
    while (spfa(cmp2))
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        ans2 += dis[t] * dfs(s,inf);
    }
    printf("%d\n%d",ans1,ans2);
    return 0;
}