#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = maxn << 1;
int n,nn,s,t,idx = 1;
int flow,cost;
bool vis[maxm];
int a[maxn],b[maxn],c[maxn];
int head[maxm],num[maxm],dis[maxm],cur[maxm];
struct edge{int v,w,c,nxt;}e[maxm << 2];
inline void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
inline bool spfa()
{
    memset(dis,0x3f,sizeof(int) * (nn + 5));
    memset(vis,0,sizeof(bool) * (nn + 5));
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
        if (!vis[v] && e[i].w && dis[v] == dis[u] + e[i].c)
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
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 2; i <= n; i++)
    {
        num[++nn] = b[i] = abs(a[i] - a[i - 1]);
        num[++nn] = c[i] = abs(a[i] + a[i - 1]);
    }
    sort(num + 1,num + nn + 1);
    nn = unique(num + 1,num + nn + 1) - num - 1;
    s = nn + 1,t = nn + 2;
    for (int i = 2; i <= n; i++)
    {
        b[i] = lower_bound(num + 1,num + nn + 1,b[i]) - num;
        c[i] = lower_bound(num + 1,num + nn + 1,c[i]) - num;
        add(s,b[i],1,0),add(b[i],c[i],1,1);
    }
    for (int i = 1; i <= nn; i++)
        add(i,t,1,0);
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (nn + 5));
        int tmp = dfs(s,inf);
        flow += tmp;
        cost += dis[t] * tmp;
    }
    if (flow != n - 1)
        printf("-1");
    else
        printf("%d",(cost + 1) >> 1);
    return 0;
}