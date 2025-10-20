#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 1e5 + 5;
int n,m,nn,s,t,idx = 1;
int a[105][105],b[105][105];
int head[205],cur[205],dis[205];
struct edge{int v,w,nxt;}e[maxn];
vector<int> vec[105][105];
int col(int x){return (x - 1) / m + 1;}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (nn + 5));
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
void build()
{
    for (int i = 1; i <= n; i++)
        add(s,i,1),add(i + n,t,1);
}
void dinic()
{
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (nn + 5));
        dfs(s,inf);
    }
}
void make(int j)
{
    for (int u = n + 1; u <= n << 1; u++)
    {
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (e[i].w)
            {
                e[i].w = 0;
                b[v][j] = vec[v][u - n].back();
                vec[v][u - n].pop_back();
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    nn = n << 1;
    s = nn + 1,t = s + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            add(i,col(a[i][j]) + n,1);
            vec[i][col(a[i][j])].push_back(a[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        build();
        dinic();
        make(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << b[i][j] << " \n"[j == m];
            a[col(b[i][j])][j] = b[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " \n"[j == m];
    return 0;
}