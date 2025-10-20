#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 1e4 + 5;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,s,t,idx = 1;
int head[maxn],cur[maxn],dis[maxn];
struct edge{int v,w,nxt;}e[maxn * 5];
int toint(int x,int y){return (x - 1) * m + y;}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n * m + 5));
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
signed main()
{
    scanf("%d%d",&n,&m);
    s = n * m + 1,t = s + 1;
    int val = 0,sum = 0,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&val);
            sum += val;
            if ((i + j) & 1)
            {
                add(s,toint(i,j),val);
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dir[k][0],y = j + dir[k][1];
                    if (x >= 1 && x <= n && y >= 1 && y <= m)
                        add(toint(i,j),toint(x,y),inf);
                }
            }
            else
                add(toint(i,j),t,val);
        }
    }
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n * m + 5));
        ans += dfs(s,inf);
    }
    printf("%d",sum - ans);
    return 0;
}