#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,s,t,idx = 1;
int p,m,f,cost;
bool vis[4005];
int head[4005],cur[4005],dis[4005];
struct edge{int v,w,c,nxt;}e[maxn];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
void ins(int u,int v,int w,int c){adde(u,v,w,c),adde(v,u,0,-c);}
bool spfa()
{
    memset(vis,0,sizeof(bool) * (n * 2 + 5));
    memset(dis,0x3f,sizeof(int) * (n * 2 + 5));
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
    scanf("%lld",&n);
    s = 0,t = n << 1 | 1;
    for (int i = 1; i < n; i++)
        ins(i + n,i + n + 1,inf,0);// 每天晚上可以把脏的留到第二天晚上
    scanf("%lld",&p);
    for (int i = 1; i <= n; i++)
        ins(s,i,inf,p);// 每天早上可以买 inf 条干净的
    scanf("%lld%lld",&f,&m);
    for (int i = 1; i + f <= n; i++)
        ins(i + n,i + f,inf,m);// 每天可以把脏的拿去洗
    scanf("%lld%lld",&f,&m);
    for (int i = 1; i + f <= n; i++)
        ins(i + n,i + f,inf,m);// 每天可以把脏的拿去洗
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        ins(s,i + n,x,0);// 每天晚上从源点获得 x 条脏的
        ins(i,t,x,0);// 每天早上从给汇点 x 条干净的
    }
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (n * 2 + 5));
        cost += dfs(s,inf) * dis[t];
    }
    printf("%lld",cost);
    return 0;
}