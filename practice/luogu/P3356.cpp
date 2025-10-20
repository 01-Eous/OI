#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)//,cerr << u << ' ' << v << ' ' << c << endl
using namespace std;
const int dir[2][2] = {1,0,0,1};
int q,n,m,s,t,py;
int cnt,idx = 1;
bool vis[2505];
int mp[40][40],id[40][40];
int head[2505],cur[2505],dis[2505];
struct edge{int v,w,c,nxt;}e[100005];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,~0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
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
            if (e[i].w && dis[v] < dis[u] + e[i].c)
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
    return dis[t] != ~inf;
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
        if (e[i].w && !vis[v] && dis[v] == dis[u] + e[i].c)
        {
            int tmp = dfs(v,min(maxf,e[i].w));
            e[i].w -= tmp,e[i ^ 1].w += tmp;
            maxf -= tmp,res += tmp;
        }
    }
    if (!res)
        dis[u] = ~inf;
    return res;
}
void print(int Nahida)
{
    int x = 1,y = 1;
    while (1)
    {
        if (x == n && y == m)
            break;
        int u = id[x][y] + py;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (!e[i ^ 1].w)
                continue;
            if (v == id[x + 1][y])
            {
                printf("%d 0\n",Nahida);
                x++,e[i ^ 1].w--;
                break;
            }
            if (v == id[x][y + 1])
            {
                printf("%d 1\n",Nahida);
                y++,e[i ^ 1].w--;
                break;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q >> m >> n;
    py = n * m;
    s = py << 1 | 1,t = s + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] != 1)
                id[i][j] = ++cnt;
        }
    }
    add(s,id[1][1],q,0);
    add(id[n][m] + py,t,q,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 1)
                continue;
            add(id[i][j],id[i][j] + py,inf,0);
            if (mp[i][j])
                add(id[i][j],id[i][j] + py,1,1);
            for (int k = 0; k < 2; k++)
                if (int x = i + dir[k][0],y = j + dir[k][1]; id[x][y])
                    add(id[i][j] + py,id[x][y],inf,0);
        }
    }
    int ans = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf) * dis[t];
    }
    cerr << ans << endl;
    for (int i = 1; i <= q; i++)
        print(i);
    return 0;
}