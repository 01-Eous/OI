#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,x,y,idx;
int head[maxn];
bool vis1[maxn],vis2[maxn];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void bfs(int s,bool *vis)
{
    memset(vis,0,sizeof(bool) * (n + 5));
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (vis[v])
                continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}
signed main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int u,v;
    while (m--)
    {
        scanf("%d%d",&u,&v);
        adde(v,u);
    }
    bfs(x,vis1),bfs(y,vis2);
    int min1 = 2;
    for (int i = 1; i <= n; i++)
    {
        if (vis1[i] && vis2[i])
        {
            min1 = 1;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ",min(min1,!vis1[i] + !vis2[i]));
    return 0;
}