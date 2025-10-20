#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
bool vis[maxn];
int fa[maxn];
vector<array<int,3>> e;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
signed main()
{
    scanf("%lld%lld",&n,&k);
    int u,v,w,ans = 0;
    while (k--)
    {
        scanf("%lld",&u);
        vis[u] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        e.push_back({w,u,v});
        ans += w;
    }
    sort(e.begin(),e.end(),greater<>());
    iota(fa,fa + n,0);
    for (auto [w,u,v] : e)
    {
        u = find(u),v = find(v);
        if (vis[u] && vis[v])
            continue;
        ans -= w;
        fa[u] = v;
        vis[u] = vis[v] = vis[u] || vis[v];
    }
    printf("%lld",ans);
    return 0;
}