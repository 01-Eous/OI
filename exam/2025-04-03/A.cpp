#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
char buf[1 << 23],*p1 = buf,*p2 = buf;
const int maxn = 5e5 + 5;
int n,k,idx,ssiz,rt,cnt;
bool vis[maxn];
int cls[maxn],top;
int p[maxn],ans[maxn],max1[maxn];
int head[maxn],siz[maxn],wei[maxn];
pair<int,int> tmp[maxn];
struct edge{int v,w,nxt;}e[maxn << 1];
void read(int &x)
{
    x = 0;
    char ch = getchar();
    while (!isdigit(ch))ch = getchar();
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dfs1(int u,int fa)
{
    siz[u] = 1,wei[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v] || v == fa)
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int fa,int dis)
{
    tmp[++cnt] = {p[u],dis};
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (!vis[v] && v != fa)
            dfs2(v,u,dis + w);
    }
}
void dfs(int u)
{
    vis[u] = 1;
    assert(!top);
    max1[p[u]] = 0;
    cls[++top] = p[u];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (vis[v])
            continue;
        cnt = 0;
        dfs2(v,u,w);
        for (int i = 1; i <= cnt; i++)
            ans[tmp[i].first] = max(ans[tmp[i].first],max1[tmp[i].first] + tmp[i].second);
        for (int i = 1; i <= cnt; i++)
        {
            max1[tmp[i].first] = max(max1[tmp[i].first],tmp[i].second);
            cls[++top] = tmp[i].first;
        }
    }
    while (top)
        max1[cls[top--]] = -inf;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        rt = 0,ssiz = siz[v];
        dfs1(v,u),dfs(rt);
    }
}
signed main()
{
    read(n),read(k);
    fill(max1 + 1,max1 + k + 1,-inf);
    for (int i = 1; i <= n; i++)
        read(p[i]);
    for (int i = 1,u,v,w; i < n; i++)
    {
        read(u),read(v),read(w);
        adde(u,v,w),adde(v,u,w);
    }
    wei[0] = inf;
    rt = 0,ssiz = n;
    dfs1(1,0),dfs(rt);
    for (int i = 1; i <= k; i++)
        printf("%lld\n",ans[i]);
    return 0;
}