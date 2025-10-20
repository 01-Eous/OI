#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define id(x,y) ((x - 1) * (n + 1) + y)
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 2e5 + 5;
int n,m,k,s,t,idx = 1;
int cap[105],num[105],sta[105][105];
int fa[maxn],head[maxn],cur[maxn],dis[maxn];
struct edge{int v,w,nxt;}e[maxn];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x != y)
        fa[x] = y;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(dis));
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
            assert(v < maxn);
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
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    iota(fa + 1,fa + n + 5,1);
    s = 2e5 + 1,t = s + 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",cap + i,num + i);
        for (int j = 0; j < num[i]; j++)
        {
            scanf("%d",sta[i] + j);
            if (sta[i][j] == 0)
                sta[i][j] = n + 1;
            else if (sta[i][j] == -1)
                sta[i][j] = n + 2;
        }
        for (int j = 1; j < num[i]; j++)
            merge(sta[i][j - 1],sta[i][j]);
    }
    if (find(n + 1) != find(n + 2))
        return printf("0"),0;
    int ans = 1,flow = 0;
    for (; ; ans++)
    {
        add(s,id(ans,n + 1),inf);
        for (int i = 1; i <= m; i++)
        {
            int x = (ans - 1) % num[i],y = ans % num[i];
            if (sta[i][x] == n + 2)
                x = t;
            else
                x = id(ans,sta[i][x]);
            if (sta[i][y] == n + 2)
                y = t;
            else
                y = id(ans + 1,sta[i][y]);
            add(x,y,cap[i]);
        }
        while (bfs())
        {
            memcpy(cur,head,sizeof(head));
            flow += dfs(s,inf);
        }
        if (flow >= k)
            break;
        for (int i = 1; i <= n + 1; i++)
            add(id(ans,i),id(ans + 1,i),inf);
    }
    printf("%d",ans);
    return 0;
}