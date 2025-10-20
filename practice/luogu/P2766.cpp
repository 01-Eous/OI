#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w) adde(u,v,w),adde(v,u,0)
using namespace std;
int n,s,t,idx = 1;
int a[505],dp[505];
int head[505],cur[505],dis[505];
struct edge{int v,w,nxt;}e[100005];
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
    scanf("%d",&n);
    if (n == 1)
        return printf("1\n1\n1");
    s = n << 1 | 1,t = s + 1;
    int max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i])
                dp[i] = max(dp[i],dp[j] + 1);
        max1 = max(max1,dp[i]);
    }
    printf("%d\n",max1);
    for (int i = 1; i <= n; i++)
    {
        add(i,i + n,1);
        if (dp[i] == 1)
            add(s,i,1);
        if (dp[i] == max1)
            add(i + n,t,1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i] && dp[i] == dp[j] + 1)
                add(j + n,i,1);
    int ans = 0;
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    printf("%d\n",ans);
    add(1,1 + n,inf),add(s,1,inf);
    if (dp[n] == max1)
        add(n,n + n,inf),add(n + n,t,inf);
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    printf("%d\n",ans);
    return 0;
}