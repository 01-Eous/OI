#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,m,s,t,val,idx = 1;
bool vis[205];
int head[205],cur[205],dis[205];
struct edge{int v,w,c,nxt;}e[100005],ori[100005];
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
    memset(dis,val,sizeof(int) * (n + m + 5));
    memset(vis,0,sizeof(bool) * (n + m + 5));
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
        if (e[i].w && !vis[v] && dis[v] == dis[u] + e[i].c)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    vis[u] = 0;
    if (!res)
        dis[u] = val;
    return res;
}
signed main()
{
    scanf("%d%d",&n,&m);
    s = n + m + 1,t = s + 1;
    int x;
    for (int i = 1; i <= n; i++)
        scanf("%d",&x),add(s,i,x,0);
    for (int i = 1; i <= m; i++)
        scanf("%d",&x),add(i + n,t,x,0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",&x),add(i,j + n,inf,x);
    int ans1 = 0,ans2 = 0;
    val = inf;
    while (spfa(cmp1))
    {
        memcpy(cur,head,sizeof(int) * (n + m + 5));
        ans1 += dfs(s,inf) * dis[t];
    }
    memcpy(e,ori,sizeof(edge) * (idx + 5));
    val = ~inf;
    while (spfa(cmp2))
    {
        memcpy(cur,head,sizeof(int) * (n + m + 5));
        ans2 += dfs(s,inf) * dis[t];
    }
    printf("%d\n%d",ans1,ans2);
    return 0;
}