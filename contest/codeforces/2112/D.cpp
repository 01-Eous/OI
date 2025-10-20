#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,idx,rt;
bool ans[maxn];
int u[maxn],v[maxn];
int fa[maxn],son[maxn];
int head[maxn],in[maxn],dep[maxn];
struct edge{int v,id,nxt;}e[maxn << 2];
void adde(int u,int v,int id)
{
    e[++idx] = {v,id,head[u]};
    head[u] = idx,in[u]++;
}
void dfs1(int u,int pre)
{
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,id = e[i].id;
        if (v == pre)
            continue;
        ans[id] = dep[u] & 1;
        dfs1(v,u),son[u]++;
    }
}
void dfs2(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,id = e[i].id;
        if (v == fa[u])
            continue;
        ans[id] ^= 1;
        dfs2(v);
    }
}
void solve()
{
    scanf("%d",&n),idx = 0;
    memset(in,0,sizeof(int) * (n + 5));
    memset(fa,0,sizeof(int) * (n + 5));
    memset(son,0,sizeof(int) * (n + 5));
    memset(dep,0,sizeof(int) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d",u + i,v + i);
        adde(u[i],v[i],i);
        adde(v[i],u[i],i);
    }
    rt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] != 2)
        {
            rt = i;
            break;
        }
    }
    dfs1(rt,0);
    bool fl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] && son[i] == 1)
        {
            dfs2(i);
            fl = 1;
            break;
        }
    }
    if (!fl)
        return (void)puts("NO");
    puts("YES");
    for (int i = 1; i < n; i++)
    {
        if (dep[u[i]] > dep[v[i]])
            swap(u[i],v[i]);
        if (ans[i])
            swap(u[i],v[i]);
        printf("%d %d\n",u[i],v[i]);
    }
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}