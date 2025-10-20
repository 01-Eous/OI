#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e4 + 5;
int n,rt,ssiz,ans;
bool vis[maxn];
int siz[maxn],wei[maxn];
vector<pii> g[maxn];
void dfs1(int u,int fa)
{
    siz[u] = 1,wei[u] = 0;
    for (auto &[v,w] : g[u])
    {
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - wei[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(array<int,3> &cnt,int dis,int u,int fa)
{
    cnt[dis % 3]++;
    for (auto &[v,w] : g[u])
        if (v != fa && !vis[v])
            dfs2(cnt,dis + w,v,u);
}
void calc(int u)
{
    array<int,3> tot = {0,0,0};
    vector<array<int,3>> cnt;
    for (auto &[v,w] : g[u])
    {
        if (vis[v])
            continue;
        cnt.push_back({0,0,0});
        dfs2(cnt.back(),w,v,u);
        tot[0] += cnt.back()[0];
        tot[1] += cnt.back()[1];
        tot[2] += cnt.back()[2];
    }
    ans += tot[0] << 1;
    for (auto &[c0,c1,c2] : cnt)
    {
        ans += c0 * (tot[0] - c0);
        ans += c1 * (tot[2] - c2);
        ans += c2 * (tot[1] - c1);
    }
}
void dfs(int u)
{
    vis[u] = 1;
    calc(u);
    for (auto &[v,w] : g[u])
    {
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,u,v,w; i < n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    ans += n;
    int tmp = __gcd(ans,n * n);
    cout << ans / tmp << '/' << n * n / tmp;
    return 0;
}