#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,idx;
int head[maxn];
int dp1[maxn],dp2[maxn];
struct edge{int v,w,nxt;}e[maxn << 2];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    int max1 = 0,max2 = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (v == fa)
            continue;
        dfs(v,u);
        dp1[u] += max(dp1[v],dp2[v]);
        dp2[u] += max(dp1[v],dp2[v]);
        int tmp = dp1[v] + w - max(dp1[v],dp2[v]);
        if (tmp > max1)
        {
            max2 = max1;
            max1 = tmp;
        }
        else if (tmp > max2)
            max2 = tmp;
    }
    dp1[u] += max1;
    dp2[u] += max1 + max2;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        adde(u,v,w),adde(v,u,w);
    }
    dfs(1,0);
    printf("%lld",max(dp1[1],dp2[1]));
    return 0;
}