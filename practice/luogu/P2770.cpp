#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,m,s,t,idx = 1;
bool vis[105];
int head[105],cur[105],dis[105];
string str[105],u,v;
map<string,int> id;
struct edge{int v,w,c,nxt;}e[100005];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,~0x3f,sizeof(int) * ((n << 1) + 5));
    memset(vis,0,sizeof(bool) * ((n << 1) + 5));
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
    vis[u] = 0;
    if (!res)
        dis[u] = ~inf;
    return res;
}
void print1(int u)
{
    vis[u] = 1;
    cout << str[u - n] << '\n';
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v <= n && !e[i].w)
        {
            print1(v + n);
            break;
        }
    }
}
void print2(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v <= n && !vis[v + n] && !e[i].w)
        {
            print2(v + n);
            // break;
        }
    }
    cout << str[u - n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    s = 1,t = n << 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        id[str[i]] = i;
    }
    add(1,1 + n,2,1),add(n,n + n,2,1);
    for (int i = 2; i < n; i++)
        add(i,i + n,1,1);
    bool fl = 0;
    while (m--)
    {
        cin >> u >> v;
        int x = id[u],y = id[v];
        if (x > y)
            swap(x,y);
        fl |= (x == 1 && y == n);
        add(id[u] + n,id[v],1,0);
    }
    int flow = 0,cost = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * ((n << 1) + 5));
        int tmp = dfs(s,inf);
        flow += tmp;
        cost += tmp * dis[t];
    }
    if (flow >= 2)
        cout << cost - 2 << '\n';
    else if (flow == 1 && fl)
        return cout << "2\n" << str[1] << '\n' << str[n] << '\n' << str[1],0;
    else
        return cout << "No Solution!",0;
    memset(vis,0,sizeof(bool) * ((n << 1) + 5));
    print1(n + 1),print2(n + 1);
    return 0;
}