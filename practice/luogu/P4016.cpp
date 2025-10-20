#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,idx = 1,s,t;
bool vis[105];
int head[105],dis[105],cur[105];
struct edge{int v,w,c,nxt;}e[1005];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
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
            if (e[i].w && dis[v] > dis[u] + e[i].c)
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
    return dis[t] != inf;
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
        dis[u] = inf;
    return res;
}
signed main()
{
    scanf("%lld",&n);
    s = n + 1,t = s + 1;
    int sum = 0;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        add(s,i,x,0);
        sum += x;
    }
    sum /= n;
    for (int i = 1,x; i <= n; i++)
    {
        add(i,t,sum,0);
        x = i - 1;
        if (x < 1)
            x = n;
        add(i,x,inf,1);
        x = i + 1;
        if (x > n)
            x = 1;
        add(i,x,inf,1);
    }
    int ans = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        ans += dis[t] * dfs(s,inf);
    }
    printf("%lld",ans);
    return 0;
}