#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
const int maxn = 2e5 + 5;
int n,m,k;
int s,t,idx;
int u[maxn],v[maxn],w[maxn];
int head[205],cur[205],dis[205];
struct edge{int v,w,nxt;}e[maxn];
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
bool chk(int mid)
{
    memset(head,0,sizeof(int) * (n + 5));
    idx = 1;
    for (int i = 1; i <= m; i++)
        if (w[i] <= mid)
            add(u[i],v[i],1),add(v[i],u[i],1);
    int res = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(int) * (n + 5));
        res += dfs(s,inf);
    }
    return res >= k;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    s = 1,t = n;
    int l = 1,r = 0,mid,ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        r = max(r,w[i]);
    }
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}