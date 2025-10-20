#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,m,q,idx,max1,max0;
int a[maxn],head[maxn],dis[maxn][2];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void bfs(int st)
{
    queue<pii> q;
    memset(dis,0x3f,sizeof(int) * 2 * (n + 5));
    dis[st][0] = 0;
    q.push({st,0});
    while (!q.empty())
    {
        int u = q.front().first;
        int lst = q.front().second;
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,cur = lst ^ 1;
            if (dis[v][cur] == inf)
            {
                dis[v][cur] = dis[u][lst] + 1;
                q.push({v,cur});
            }
        }
    }
}
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    idx = 0,max0 = max1 = -inf;
    memset(head,0,sizeof(int) * (n + 5));
    int sum = 0,min1 = inf;
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld",a + i);
        sum += a[i];
        if (a[i] & 1)
            min1 = min(min1,a[i]);
    }
    if (sum & 1)
    {
        max1 = sum;
        max0 = sum - min1;
    }
    else
    {
        max0 = sum;
        max1 = sum - min1;
    }
    int u,v;
    while (m--)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        bool fl = 0;
        fl |= max0 >= dis[i][0];
        fl |= max1 >= dis[i][1];
        putchar('0' + fl);
    }
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}