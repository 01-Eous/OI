#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define toint(x,y) ((x - 1) * n + y)
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 1e5 + 5;
const int dir[8][2] = {1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
int n,m,s,t,idx = 1;
bool mp[205][205];
int head[maxn],cur[maxn],dis[maxn];
struct edge{int v,w,nxt;}e[maxn << 2];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n * n + 5));
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    s = n * n + 1,t = s + 1;
    int u,v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        mp[u][v] = 1;   
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j])
                continue;
            if ((i + j) & 1)
                add(s,toint(i,j),1);
            else
                add(toint(i,j),t,1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!((i + j) & 1))
                continue;
            for (int k = 0; k < 8; k++)
            {
                int x = i + dir[k][0],y = j + dir[k][1];
                if (1 <= x && x <= n && 1 <= y && y <= n && !mp[x][y])
                    add(toint(i,j),toint(x,y),inf);
            }
        }
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n * n + 5));
        ans += dfs(s,inf);
    }
    printf("%d",n * n - m - ans);
    return 0;
}