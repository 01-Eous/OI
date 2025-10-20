#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int m,n,s,t,idx = 1;
char in[5005];
int head[105],cur[105],dis[105];
struct edge{int v,w,nxt;}e[5005];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void add(int u,int v,int w){adde(u,v,w),adde(v,u,0);}
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
    scanf("%d%d",&m,&n);
    s = 0,t = m + n + 1;
    int ans = 0,sum = 0;
    for (int i = 1,val,u; i <= m; i++)
    {
        scanf("%d",&val);
        sum += val;
        add(s,i,val);
        cin.getline(in,5000);
        int ulen = 0;
        while (sscanf(in + ulen,"%d",&u) == 1)
        {
            add(i,u + m,inf);
            if (!u)
                ulen++;
            while (u)
            {
                ulen++;
                u /= 10;
            }
            ulen++;
        }
    }
    for (int i = 1,val; i <= n; i++)
        scanf("%d",&val),add(i + m,t,val);
    while (bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans += dfs(s,inf);
    }
    for (int i = 1; i <= m; i++)
        if (dis[i] != inf)
            printf("%d ",i);
    putchar('\n');
    for (int i = 1; i <= n; i++)
        if (dis[i + m] != inf)
            printf("%d ",i);
    printf("\n%d",sum - ans);
    return 0;
}