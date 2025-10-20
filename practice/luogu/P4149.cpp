#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,k,_min;
pii dis[maxn];
bool vis[maxn];
int head[maxn],idx,a[maxn],cnt;
int siz[maxn],wei[maxn],bel[maxn],ssiz,rt;
struct edge{int v,w,nxt;}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = edge{v,w,head[u]};
    head[u] = idx;
}
bool cmp(int x,int y){return dis[x] < dis[y];}
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
void dfs2(int u,pii dist,int root,int fa)
{
    a[++cnt] = u;
    dis[u] = dist,bel[u] = root;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs2(v,{dist.first + e[i].w,dist.second + 1},root,u);
}
void calc(int u)
{
    a[cnt = 1] = u;
    dis[u] = {0,0},bel[u] = u;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; !vis[v])
            dfs2(v,{e[i].w,1},v,0);
    sort(a + 1,a + cnt + 1,cmp);
    int l = 1,r = cnt;
    while (l != r)
    {
        if (dis[a[l]].first + dis[a[r]].first > k)
            r--;
        else if (dis[a[l]].first + dis[a[r]].first < k)
            l++;
        else if (bel[a[l]] == bel[a[r]])
            l++;
        else
            _min = min(_min,dis[a[l]].second + dis[a[r--]].second);
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
        dfs1(v,u);
        dfs(rt);
    }
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        u++,v++;
        adde(u,v,w);
        adde(v,u,w);
    }
    wei[rt = 0] = _min = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    printf("%lld",_min == inf ? -1 : _min);
    return 0;
}