#include<iostream>
#include<algorithm>
#include<vector>
#define inf 0x3f3f3f3f
#define mkp make_pair
using namespace std;
const int maxn = 4e4 + 5;
int n,k;
bool vis[maxn];
int rt,ssiz,ans;//root,sum_size
int head[maxn],idx;
int siz[maxn],wei[maxn];//size,weight
struct edge
{
    int v,w,nxt;
    edge(int v = 0,int w = 0,int nxt = 0):v(v),w(w),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = edge(v,w,head[u]);
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
    if (wei[rt] > wei[u])
        rt = u;
}
void dfs2(int u,int dis,int fa,vector<int>&a)
{
    a.push_back(dis);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (v != fa && !vis[v])
            dfs2(v,dis + w,u,a);
    }
}
int calc(int u,int dis)
{
    vector<int>a;
    dfs2(u,dis,0,a);
    sort(a.begin(),a.end());
    vector<int>::iterator l = a.begin(),r = a.end() - 1;
    int ret = 0;
    for (;; l++)
    {
        while (l <= r && *l + *r > k)
            r--;
        if (r < l)
            break;
        ret += r - l + 1;
    }
    return ret;
}
void dfs(int u)
{
    ans += calc(u,0);
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (vis[v])
            continue;
        ans -= calc(v,w);
        rt = 0,ssiz = siz[v];
        dfs1(v,0);
        dfs(rt);
    }
}
void init()
{
    fill(vis + 1,vis + n + 1,0);
    fill(head + 1,head + n + 1,0);
    idx = ans = rt = 0;
    wei[rt] = inf;
}
signed main()
{
    scanf("%d",&n);
    init();
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    scanf("%d",&k);
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    printf("%d\n",ans - n);
    return 0;
}