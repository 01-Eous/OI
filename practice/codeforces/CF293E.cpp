#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define lowbit(x) ((x) & -(x))
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int n,len,w,ans;
bool vis[maxn];
int head[maxn],idx,tree[maxn];
int siz[maxn],wei[maxn],ssiz,rt;
vector<pii>a;
struct edge{int v,w,nxt;}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = edge{v,w,head[u]};
    head[u] = idx;
}
void add(int i,int x)
{
    if (i <= 0)
        return;
    for (; i <= n + 1; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    if (i <= 0)
        return 0;
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret += tree[i];
    return ret;
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
void dfs2(int u,pii dis,int fa)
{
    a.push_back(dis);
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs2(v,{dis.first + e[i].w,dis.second + 1},u);
}
int calc(int u,pii dis)
{
    a.clear();
    dfs2(u,dis,0);
    sort(a.begin(),a.end());
    for (auto i : a)
        add(i.second + 1,1);
    auto l = a.begin(),r = a.end() - 1;
    int ret = 0;
    while (l != r)
    {
        if (l->first + r->first <= w)
        {
            add(l->second + 1,-1);
            ret += que(len - l->second + 1);
            l++;
        }
        else
        {
            add(r->second + 1,-1);
            r--;
        }
    }
    add(l->second + 1,-1);
    return ret;
}
void dfs(int u)
{
    vis[u] = 1;
    ans += calc(u,{0,0});
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        ans -= calc(v,{e[i].w,1});
        wei[rt = 0] = inf;
        ssiz = siz[v];
        dfs1(v,u);
        dfs(rt);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> len >> w;
    for (int u = 2,v,w; u <= n; u++)
    {
        cin >> v >> w;
        adde(u,v,w);
        adde(v,u,w);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    cout << ans;
    return 0;
}