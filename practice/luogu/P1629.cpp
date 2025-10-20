#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1005;
int n,m;
bool vis[maxn];
int dis1[maxn],dis2[maxn];
vector<pii>g1[maxn],g2[maxn];
void dij(vector<pii> g[],int dis[],int st)
{
    priority_queue<pii,vector<pii>,greater<pii>>q;
    fill(vis + 1,vis + n + 1,0);
    fill(dis + 1,dis + n + 1,inf);
    dis[st] = 0;
    q.push({0,st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v,w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v,w; i <= m; i++)
    {
        cin >> u >> v >> w;
        g1[u].push_back({v,w});
        g2[v].push_back({u,w});
    }
    dij(g1,dis1,1);
    dij(g2,dis2,1);
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dis1[i] + dis2[i];
    cout << ans;
    return 0;
}