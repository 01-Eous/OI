#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define add(u,v,w,c) adde(u,v,w,c),adde(v,u,0,-c)
using namespace std;
int n,k,s,t,idx = 1,cnt;
bool vis[1005];
int num[1005],l[505],r[505];
int head[1005],cur[1005],dis[1005];
struct edge{int v,w,c,nxt;}e[100005];
void adde(int u,int v,int w,int c)
{
    e[++idx] = {v,w,c,head[u]};
    head[u] = idx;
}
bool spfa()
{
    memset(dis,~0x3f,sizeof(int) * (cnt + 5));
    memset(vis,0,sizeof(bool) * (cnt + 5));
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
int dinic()
{
    int res = 0;
    while (spfa())
    {
        memcpy(cur,head,sizeof(int) * (cnt + 5));
        res += dis[t] * dfs(s,inf);
    }
    return res;
}
signed main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",l + i,r + i);
        if (l[i] > r[i])
            swap(l[i],r[i]);
        num[++cnt] = l[i];
        num[++cnt] = r[i];
    }
    sort(num + 1,num + cnt + 1);
    cnt = unique(num + 1,num + cnt + 1) - num - 1;
    s = cnt + 1,t = s + 1;
    add(s,1,k,0),add(cnt,t,k,0);
    for (int i = 1; i < cnt; i++)
        add(i,i + 1,k,0);
    for (int i = 1; i <= n; i++)
    {
        l[i] = lower_bound(num + 1,num + cnt + 1,l[i]) - num;
        r[i] = lower_bound(num + 1,num + cnt + 1,r[i]) - num;
        add(l[i],r[i],1,num[r[i]] - num[l[i]]);
    }
    printf("%d",dinic());
    return 0;
}