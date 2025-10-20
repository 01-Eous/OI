#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const int maxn = 1e5 + 5;
int n,nn,m,idx = 1,s,t;
int head[2500],cur[2500],dis[2500];
struct edge{int v,w,nxt;}e[maxn];
int id(int i,int j){return (i - 1) * n + j;}
bool bound(int x,int y)
{return 1 <= x && x <= n && 1 <= y && y <= n;}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
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
    cin >> n >> m,nn = n * n;
    s = nn << 1 | 1,t = s + 1;
    for (int i = 1; i <= nn; i++)
        add(i,i + nn,1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < 4; k++)
                if (int x = i + dx[k],y = j + dy[k]; bound(x,y))
                    add(id(i,j) + nn,id(x,y),1);
    for (int i = 1; i < n; i++)
    {
        add(id(1,i) + nn,t,1);
        add(id(i,n) + nn,t,1);
    }
    for (int i = n; i > 1; i--)
    {
        add(id(n,i) + nn,t,1);
        add(id(i,1) + nn,t,1);
    }
    for (int i = 1,x,y; i <= m; i++)
    {
        cin >> x >> y;
        add(s,id(x,y),1);
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    cout << (ans == m ? "YES" : "NO");
    return 0;
}