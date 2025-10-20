#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using i3 = array<int,3>;
const int maxn = 2e5 + 5;
int n,m;
vector<i3> g;
int fa[maxn],val[maxn];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y,int w)
{
    x = find(x),y = find(y);
    if (x == y)
        return;
    fa[x] = y;
    val[y] = min({val[x],val[y],w});
}
void solve()
{
    cin >> n >> m;
    g.clear(),g.reserve(m);
    iota(fa + 1,fa + n + 1,1);
    fill(val + 1,val + n + 1,inf);
    while (m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g.push_back({w,u,v});
    }
    sort(g.begin(),g.end());
    int ans = inf;
    for (auto [w,u,v] : g)
    {
        merge(u,v,w);
        if (int x = find(1); x == find(n))
            ans = min(ans,val[x] + w);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}