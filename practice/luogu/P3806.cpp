#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e4 + 5;
int n,m;
int qry[105];
int head[maxn],idx;
bool vis[maxn],ans[105];
int dis[maxn],bel[maxn];
int siz[maxn],wei[maxn],ssiz,rt;
struct edge{int v,w,nxt;}e[maxn << 1];
bool cmp(int x,int y){return dis[x] < dis[y];}
void adde(int u,int v,int w)
{
    e[++idx] = edge{v,w,head[u]};
    head[u] = idx;
}
void dfs1(int u,int fa)
{
    siz[u] = 1,wei[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(vector<int>&a,int u,int dist,int fa,int root)
{
    a.push_back(u);
    dis[u] = dist,bel[u] = root;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v != fa && !vis[v])
            dfs2(a,v,dist + e[i].w,u,root);
    }
}
void calc(int u)
{
    vector<int>a = {u};
    dis[u] = 0,bel[u] = u;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!vis[v])
            dfs2(a,v,e[i].w,0,v);
    }
    sort(a.begin(),a.end(),cmp);
    for (int i = 1; i <= m; i++)
    {
        auto l = a.begin(),r = a.end() - 1;
        while (l != r && !ans[i])
        {
            if (dis[*l] + dis[*r] > qry[i])
                r--;
            else if (dis[*l] + dis[*r] < qry[i])
                l++;
            else if (bel[*l] == bel[*r])
            {
                if (dis[*r] == dis[*(r - 1)])
                    r--;
                else
                    l++;
            }
            else
                ans[i] = 1;
        }
    }
}
void dfs(int u)
{
    vis[u] = 1;
    calc(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        wei[rt = 0] = inf;
        ssiz = siz[v];
        dfs1(v,0);
        dfs(rt);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",qry + i);
        if (!qry[i])
            ans[i] = 1;
    }
    wei[rt = 0] = inf;
    dfs1(1,0);
    dfs(rt);
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "AYE" : "NAY");
    return 0;
}