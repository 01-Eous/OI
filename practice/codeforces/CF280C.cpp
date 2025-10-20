#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,idx;
int head[maxn],dep[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    dep[u] = dep[fa] + 1;
    for (int i = head[u]; i; i = e[i].nxt)  
        if (int v = e[i].v; v != fa)
            dfs(v,u);
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1.0 / dep[i];
    printf("%.8lf",ans);
    return 0;
}