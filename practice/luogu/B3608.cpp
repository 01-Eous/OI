#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxm = 3e4 + 5;
int n,m,s,t,idx = 1;
int flow,cost;
bool vis[405];
int head[405],cur[405],dis[405];
struct edge{int v,nxt,c,w;}e[maxm];
void adde(int u,int v,int c,int w)
{
    e[++idx] = {v,head[u],c,w};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    queue<int> q;
    dis[s] = 0;
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
            maxf -= tmp,res += tmp,cost += tmp * e[i].c;
        }
    }
    vis[u] = 0;
    if (!res)
        dis[u] = inf;
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    s = 1,t = n;
    int u,v,c,w;
    while (m--)
    {
        scanf("%lld%lld%lld%lld",&u,&v,&w,&c);
        adde(u,v,c,w),adde(v,u,-c,0);
    }
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        flow += dfs(s,inf);
    }
    printf("%lld %lld",flow,cost);
    return 0;
}