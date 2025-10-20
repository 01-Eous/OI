#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
int n1,n2,n3,n;
int s,t,idx = 1;
int head[405],cur[405],dis[405];
struct edge{int v,w,nxt;}e[5005];
int id(int x,int y)
{
    if (y == 1)
        return x;
    if (y == 2)
        return x + n1;
    if (y == 3)
        return x + n1 + n2;
    return x + n1 + n2 + n2;
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
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
    cin >> n2 >> n1 >> n3;
    n = n1 + n2 + n2 + n3;
    s = n + 1,t = s + 1;
    for (int i = 1; i <= n1; i++)
        add(s,id(i,1),1);
    for (int i = 1; i <= n2; i++)
        add(id(i,2),id(i,3),1);
    for (int i = 1; i <= n3; i++)
        add(id(i,4),t,1);
    bool ch;
    for (int v = 1; v <= n2; v++)
    {
        for (int u = 1; u <= n1; u++)
        {
            cin >> ch;
            if (ch)
                add(id(u,1),id(v,2),1);
        }
    }
    for (int u = 1; u <= n2; u++)
    {
        for (int v = 1; v <= n3; v++)
        {
            cin >> ch;
            if (ch)
                add(id(u,3),id(v,4),1);
        }
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        ans += dfs(s,inf);
    }
    cout << ans;
    return 0;
}