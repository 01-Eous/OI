#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,m,s,t,idx;
int u[maxn],v[maxn];
int head[405],dis[405];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void bfs()
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
            if (dis[v] == inf)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",u + i,v + i);
        adde(u[i],v[i]),adde(v[i],u[i]);
    }
    bfs();
    printf("%lld\n",dis[t]);
    for (int i = 1; i <= m; i++)
    {
        int tmp = max(dis[u[i]],dis[v[i]]);
        if (tmp <= dis[t])
            printf("%lld\n",tmp);
        else
            puts("0");
    }
    return 0;
}