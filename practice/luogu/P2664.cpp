#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,pos;
bool vis[maxn];
int head[maxn],idx;
int siz[maxn],wei[maxn],ssiz,rt;
int col[maxn],ans[maxn];
int cnt[maxn],apr[maxn],sum;
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = edge{v,head[u]};
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
void dfs2(int u,int dis,int fa)
{
    siz[u] = 1;
    if (!apr[col[u]]++)
    {
        sum -= cnt[col[u]];
        dis++;
    }
    ans[u] += sum + dis * siz[pos];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs2(v,dis,u);
        siz[u] += siz[v];
    }
    if (!--apr[col[u]])
        sum += cnt[col[u]];
}
void dfs3(int u,int fa)
{
    if (!apr[col[u]])
    {
        cnt[col[u]] += siz[u];
        sum += siz[u];
    }
    apr[col[u]]++;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs3(v,u);
    apr[col[u]]--;
}
void clear1(int u,int fa)
{
    cnt[col[u]] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            clear1(v,u);
}
void clear2(int u,int dis,int fa)
{
    if (!apr[col[u]])
        dis++;
    apr[col[u]]++;
    ans[u] -= dis;
    ans[pos] += dis;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            clear2(v,dis,u);
    apr[col[u]]--;
    cnt[col[u]] = 0;
}
void dfs(int u)
{
    vis[u] = 1;
    ans[pos = u]++;
    vector<int>a;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; !vis[v])
            a.push_back(v);
    siz[u] = sum = cnt[col[u]] = 1,apr[col[u]]++;
    for (auto v : a)
    {
        dfs2(v,0,u);
        dfs3(v,u);
        sum += siz[v];
        siz[u] += siz[v];
        cnt[col[u]] += siz[v];
    }
    clear1(u,0),reverse(a.begin(),a.end());
    siz[u] = sum = cnt[col[u]] = 1;
    for (auto v : a)
    {
        dfs2(v,0,u);
        dfs3(v,u);
        sum += siz[v];
        siz[u] += siz[v];
        cnt[col[u]] += siz[v];
    }
    apr[col[u]]--,clear2(u,0,0);
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
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",col + i);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    for (int i = 1; i <= n; i++)
        printf("%lld\n",ans[i]);
    return 0;
}