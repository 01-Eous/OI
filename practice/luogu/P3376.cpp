#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e4 + 5;
int n,m,s,t,idx = 1;
int head[505],cur[505],dis[505];
struct edge{int v,w,nxt;}e[maxn];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (dis[v] == inf && e[i].w > 0)
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
        if (e[i].w > 0 && dis[v] == dis[u] + 1)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            res += tmp,maxf -= tmp;
        }
    }
    if (!res)
        dis[u] = 0;
    return res;
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    int u,v,w;
    while (m--)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        adde(u,v,w),adde(v,u,0);
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        ans += dfs(s,inf);
    }
    printf("%lld",ans);
    return 0;
}