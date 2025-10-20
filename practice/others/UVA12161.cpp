#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,k,ans;
bool vis[maxn];
int head[maxn],idx;
int siz[maxn],wei[maxn],ssiz,rt;
vector<pii>a;
map<int,int>mp;
struct edge{int v,d,w,nxt;}e[maxn << 1];
void read(int &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
void adde(int u,int v,int d,int w)
{
    e[++idx] = edge{v,d,w,head[u]};
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
void dfs2(int u,pii dis,int fa)
{
    a.push_back(dis);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,d = e[i].d,w = e[i].w;
        if (v == fa || vis[v])
            continue;
        dfs2(v,{dis.first + d,dis.second + w},u);
    }
}
void upd(int x,int y)
{
    auto p = mp.upper_bound(x);
    if (p == mp.begin() || (--p)->second < y)
    {
        mp[x] = y;
        p = mp.upper_bound(x);
        while (p != mp.end() && p->second <= y)
            mp.erase(p++);
    }
}
void dfs3(int u)
{
    mp.clear();
    mp[0] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        a.clear();
        dfs2(v,{e[i].d,e[i].w},u);
        for (auto &[d,w] : a)
        {
            auto p = mp.upper_bound(k - d);
            if (p != mp.begin())
                ans = max(ans,w + (--p)->second);
        }
        for (auto &[d,w] : a)
            upd(d,w);
    }
}
void dfs(int u)
{
    vis[u] = 1;
    dfs3(u);
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
void solve()
{
    read(n),read(k);
    fill(vis + 1,vis + n + 1,0);
    fill(head + 1,head + n + 1,0);
    ans = idx = 0;
    for (int i = 1,u,v,w,d; i < n; i++)
    {
        read(u),read(v),read(d),read(w);
        adde(u,v,d,w);
        adde(v,u,d,w);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
}
signed main()
{
    int t;
    read(t);
    for (int i = 1; i <= t; i++)
    {
        solve();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}