#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s,t,idx = 1;
bool vis[405];
int head[405],id[405],cur[405],dis[405];
struct edge{int v,w,nxt;}e[20005];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void add(int u,int v,int w){adde(u,v,w),adde(v,u,0);}
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    s = n << 1 | 1,t = s + 1;
    int u,v;
    while (m--)
    {
        cin >> u >> v;
        add(u,v + n,1);
    }
    for (int i = 1; i <= n; i++)
        add(s,i,1),add(i + n,t,1),id[i + n] = idx - 1;
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        ans += dfs(s,inf);
    }
    for (int i = n + 1; i <= (n << 1); i++)
    {
        if (e[id[i]].w)
        {
            print(i - n);
            putchar('\n');
        }
    }
    printf("%d",n - ans);
    return 0;
}