#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,ans;
int siz[maxn];
vector<pii>g[maxn];
void dfs(int u,int fa)
{
    siz[u] = 1;
    for (auto &[v,w] : g[u])
    {
        if (v == fa)
            continue;
        dfs(v,u);
        siz[u] += siz[v];
        ans += min(siz[v],n - siz[v]) * w << 1;
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
    dfs(1,0);
    cout << ans;
    return 0;
}