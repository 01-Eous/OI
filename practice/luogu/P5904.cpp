#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,idx,ans;
int pool[maxn << 2],*buf = pool;
int head[maxn],*dp1[maxn],*dp2[maxn];
int dep[maxn],len[maxn],fa[maxn],son[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre)
            continue;
        dfs1(v,u);
        len[u] = max(len[u],len[v]);
        if (len[v] > len[son[u]])
            son[u] = v;
    }
    len[u]++;
}
void dfs2(int u)
{
    if (son[u])
    {
        dp1[son[u]] = dp1[u] + 1;
        dp2[son[u]] = dp2[u] - 1;
        dfs2(son[u]);
    }
    dp1[u][0] = 1,ans += dp2[u][0];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dp1[v] = buf,buf += len[v] << 1;
        dp2[v] = buf,buf += len[v] << 1;
        dfs2(v);
        for (int j = 0; j < len[v]; j++)
        {
            if (j)
                ans += dp1[u][j - 1] * dp2[v][j];
            ans += dp2[u][j + 1] * dp1[v][j];
        }
        for (int j = 0; j < len[v]; j++)
        {
            dp2[u][j + 1] += dp1[u][j + 1] * dp1[v][j];
            if (j)
                dp2[u][j - 1] += dp2[v][j];
            dp1[u][j + 1] += dp1[v][j];
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    dfs1(1,0);
    dp1[1] = buf,buf += len[1] << 1;
    dp2[1] = buf,buf += len[1] << 1;
    dfs2(1);
    printf("%lld",ans);
    return 0;
}