#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1005;
int n,m;
bool vis[maxn];
int dis[maxn],cnt[maxn];
vector<pii> g[maxn];
void spfa(int st)
{
    queue<int> q;
    fill(cnt + 1,cnt + n + 1,0);
    fill(vis + 1,vis + n + 1,0);
    fill(dis + 1,dis + n + 1,inf);
    dis[st] = 0;
    q.push(st);
    vis[st] = 1;
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
                    if (++cnt[v] > n + 5)
                    {
                        cout << "Forever love";
                        exit(0);
                    }
                    vis[v] = 1;
                    q.push(v);
                }
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
        g[u].push_back({v,-w});
        // g[v].push_back({u,-w});
    }
    int ans = inf;
    spfa(1);
    ans = min(ans,dis[n]);
    spfa(n);
    ans = min(ans,dis[1]);
    cout << ans;
    return 0;
}