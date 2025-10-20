#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int m,s,t,idx = 1;
int head[65],cur[65],dis[65];
struct edge{int v,w,nxt;}e[1505];
int id(char ch)
{
    if ('A' <= ch && ch <= 'Z')
        return ch - 'A' + 1;
    else
        return ch - 'a' + 27;
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
bool bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    dis[s] = 1;
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
    cin >> m;
    s = 1,t = 26;
    char u,v;
    int w;
    while (m--)
    {
        cin >> u >> v >> w;
        adde(id(u),id(v),w),adde(id(v),id(u),0);
    }
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    cout << ans;
    return 0;
}