#include<bits/extc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n,idx,rt;
int head[maxn],vis1[maxn],vis2[maxn];
int a[maxn],b[maxn],val[maxn],ans[maxn];
struct edge{int v,id,nxt;}e[maxn << 2];
void adde(int u,int v,int id)
{
    e[++idx] = {v,id,head[u]};
    head[u] = idx;
}
void dfs1(int u)
{
    vis1[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,id = e[i].id;
        if (vis2[id])
            continue;
        vis2[id] = 1,ans[id] = u;
        if (!vis1[v])
            dfs1(v);
    }
}
void dfs2(int u)
{
    vis1[u] = 2;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,id = e[i].id;
        if (v == rt || vis2[id] == 2)
            continue;
        vis2[id] = 2,ans[id] = v;
        if (vis1[v] == 1)
            dfs2(v);
    }
}
void solve()
{
    scanf("%d",&n);
    idx = 0;
    memset(val,0,sizeof(int) * ((n << 1) + 5));
    memset(head,0,sizeof(int) * ((n << 1) + 5));
    memset(vis1,0,sizeof(int) * ((n << 1) + 5));
    memset(vis2,0,sizeof(int) * ((n << 1) + 5));
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i),val[a[i]]++;
    for (int i = 1; i <= n; i++)
        scanf("%d",b + i),val[b[i]]++;
    for (int i = 1; i <= n; i++)
    {
        adde(a[i],b[i],i);
        adde(b[i],a[i],i);
    }
    int tmp = 0;
    for (int u = 1; u <= n << 1; u++)
    {
        tmp += min(2,val[u]);
        if (!vis1[u])
        {
            dfs1(u);
            bool fl = 0;
            for (int i = head[u]; i; i = e[i].nxt)
            {
                if (ans[e[i].id] != u)
                {
                    fl = 1;
                    break;
                }
            }
            if (!fl && head[u]) 
            {
                rt = u;
                ans[e[head[u]].id] = e[head[u]].v;
                dfs2(e[head[u]].v);
            }
        }
    }
    printf("%d\n",tmp);
    for (int i = 1; i <= n; i++)
        printf("%d ",ans[i]);
    putchar('\n');
    for (int i = 1; i <= n; i++)
        printf("%d ",a[i] + b[i] - ans[i]);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}