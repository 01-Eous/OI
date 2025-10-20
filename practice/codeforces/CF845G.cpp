#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int n,m;
bool vis[maxn];
int dis[maxn],d[35];
vector<pii> g[maxn];
void ins(int x)
{
    for (int i = 30; i >= 0; i--)
    {
        if (x & (1 << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
    }
}
void dfs(int u,int dist)
{
    dis[u] = dist,vis[u] = 1;
    for (auto &[v,w] : g[u])
    {
        if (!vis[v])
            dfs(v,dist ^ w);
        else
            ins(dis[v] ^ dist ^ w);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u,v,w;
    while (m--)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    int ans = dis[n];
    for (int i = 30; i >= 0; i--)
        if ((ans ^ d[i]) < ans)
            ans ^= d[i];
    cout << ans;
    return 0;
}