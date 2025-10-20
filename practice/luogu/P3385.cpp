#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2005;
int n,m;
bool vis[maxn];
int dis[maxn],cnt[maxn];
vector<pii>g[maxn];
bool spfa(int st)
{
    queue<int>q;
    fill(dis + 1,dis + n + 1,inf);
    fill(vis + 1,vis + n + 1,0);
    fill(cnt + 1,cnt + n + 1,0);
    dis[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &[v,w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    if (++cnt[v] >= n)
                        return 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1,u,v,w; i <= m; i++)
    {
        cin >> u >> v >> w;
        if (w >= 0)
        {
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        else
            g[u].push_back({v,w});
    }
    cout << (spfa(1) ? "YES\n" : "NO\n");
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