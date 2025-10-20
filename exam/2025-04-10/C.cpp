#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,ban;
bool vis[55];
int cnt[55],c[55],f1[55],f2[55];
vector<int> vec;
struct edge{int v,nxt;};
struct Nahida
{
    edge e[105];
    int head[55],idx;
    void adde(int u,int v)
    {
        e[++idx] = {v,head[u]};
        head[u] = idx;
    }
}g1,g2;
void clear()
{
    g1.idx = g2.idx = ban = 0;
    memset(g1.head,0,sizeof(int) * (n + 5));
    memset(g2.head,0,sizeof(int) * (n + 5));
}
void dfs1(int u,int fa)
{
    f1[u] = fa;
    for (int i = g1.head[u]; i; i = g1.e[i].nxt)
    {
        int v = g1.e[i].v;
        if (v == ban || v == fa)
            continue;
        cnt[u]++;
        dfs1(v,u);
    }
}
void dfs2(int u,int fa,bool op)
{
    if (!op)// 不在本来的位置上
    {
        vec.push_back(u);
        f2[u] = fa;
    }
    else // 在本来的位置上
        vis[u] = 1;
    for (int i = g2.head[u]; i; i = g2.e[i].nxt)
    {
        int v = g2.e[i].v;
        if (v == fa)
            continue;
        if (f1[v] == u)
            dfs2(v,u,op);
        else
            dfs2(v,u,0);
    }
}
bool chk()
{
    while (1)
    {
        int cnt1 = 0,cnt2 = 0;
        // cnt1 表示需要被操作的节点数
        // cnt2 表示实施了的操作数
        for (auto u : vec)
        {
            if (!vis[u])
            {
                cnt1++;
                if (!cnt[u] && vis[f2[u]])
                {
                    cnt2++;
                    vis[u] = 1;
                    cnt[f1[u]]--;
                }
            }
        }
        if (!cnt1)
            return 1;
        if (!cnt2)
            return 0;
    }
}
void solve()
{
    scanf("%d",&n);
    clear();
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g1.adde(u,v),g1.adde(v,u);
    }
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g2.adde(u,v),g2.adde(v,u);
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        vec.clear();
        memset(cnt,0,sizeof(int) * (n + 5));
        memset(vis,0,sizeof(bool) * (n + 5));
        dfs1(i,0);
        dfs2(i,0,1);
        if (chk())
            ans = min(ans,(int)vec.size());
    }
    memset(cnt,0,sizeof(int) * (n + 5));
    dfs1(1,0);
    for (int i = 1; i <= n; i++)
        c[i] = cnt[i];
    for (int i = 1; i <= n; i++)
    {
        if (!(!c[i] || (i == 1 && c[i] == 1)))
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            // 以下是改图
            int hdi = g1.head[i],hdj = g1.head[j];
            g1.adde(i,j),g1.adde(j,i);
            ban = f1[j] = i;

            // 以下是计算
            vec.clear();
            memset(cnt,0,sizeof(int) * (n + 5));
            memset(vis,0,sizeof(bool) * (n + 5));
            dfs1(j,i);
            dfs2(i,0,1);
            if (chk())
                ans = min(ans,(int)vec.size() + 1);
            
            // 以下是还原图
            g1.idx -= 2;
            g1.head[i] = hdi,g1.head[j] = hdj;
        }
    }
    printf("%d\n",ans == inf ? -1 : ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}