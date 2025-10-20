#include<bits/extc++.h>
#define int long long
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define inf 0x3f3f3f3f3f3f3f3f
const int maxn = 1e5 + 5;
int n,mod;
bool vis[maxn];
int head[maxn],idx;
int dis[maxn],ans[maxn];
int siz[maxn],wei[maxn],rt,ssiz;
std::multiset<int>st;
struct edge{int v,w,nxt;}e[maxn << 1];
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
void dfs2(int u,int fa)
{
    st.insert(dis[u]);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (v == fa || vis[v])
            continue;
        dis[v] = (dis[u] + w) % mod;
        dfs2(v,u);
    }
}
void set(int u,int fa,bool op)
{
    if (op)
        st.insert(dis[u]);
    else
        st.erase(st.find(dis[u]));
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            set(v,u,op);
}
void dfs3(int u,int fa)
{
    ans[u] = max(ans[u],max(*(--st.lower_bound(mod - dis[u])) + dis[u],(dis[u] + *st.rbegin()) % mod));
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs3(v,u);
}
void dfs(int u)
{
    vis[u] = 1,dis[u] = 0;
    dfs2(u,0);
    ans[u] = max(ans[u],*st.rbegin());
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        set(v,u,0);
        dfs3(v,u);
        set(v,u,1);
    }
    st.clear();
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
    scanf("%lld%lld",&n,&mod);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    for (int i = 1; i <= n; i++)
        printf("%lld\n",ans[i]);
    return 0;
}