#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) (adde(u,v,w),adde(v,u,0))
using namespace std;
const int maxn = 5e6 + 5;
int m,n,s,t,idx;
bool vis[4005];
int head[4005],cur[4005],id[4005],dis[4005];
struct edge{int v,w,nxt;}e[maxn];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * ((n << 1) + 5));
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].w && dis[v] == inf)
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
        if (e[i].w && dis[v] == dis[u] + 1)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    if (!res)
        dis[u] = inf;
    return res;
}
bool chk(int mid)
{
    n = mid,idx = 1;
    s = n << 1 | 1,t = s + 1;
    memset(head,0,sizeof(int) * ((n << 1) + 5));
    for (int i = 1; i * i <= (n << 1); i++)
        for (int j = max(1,i * i - n); j <= n && i * i - j > j; j++)
            add(j,i * i - j + n,1);
    for (int i = 1; i <= n; i++)
        add(s,i,1),add(i + n,t,1),id[i + n] = idx - 1;
    int res = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        res += dfs(s,inf);
    }
    return n - res <= m;
}
void print(int u)
{
    vis[u] = 1;
    printf("%d ",u);
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v > n && v <= (n << 1) && !e[i].w && !vis[v - n])
            print(v - n);
}
signed main()
{
    scanf("%d",&m);
    int l = 1,r = 2000,mid,ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    chk(ans);
    printf("%d\n",ans);
    for (int i = n + 1; i <= (n << 1); i++)
    {
        if (e[id[i]].w)
        {
            print(i - n);
            putchar('\n');
        }
    }
    return 0;
}
