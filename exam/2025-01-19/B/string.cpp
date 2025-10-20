#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5005;
int n;
vector<vector<pii>>e;
vector<int> spfa(int st)
{
    queue<int>q;
    vector<int>dis(n + 5,inf);
    vector<bool>vis(n + 5,0);
    dis[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v,w] : e[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    e.resize(n + 5);
    vector<int>a(n + 5),b(n + 5),id(n + 5);
    vector<vector<short>>g(n + 5,vector<short>(n + 5,1));
    for (int i = 1; i <= n; i++)
    {
        e[0].push_back({i,-1});
        e[i].push_back({0,114514});
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = n; i; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (id[i] < id[j])
            {
                if (i == n || id[i + 1] <= id[j + 1])
                    g[i][j] = 0;
                else
                    g[i][j] = -1;
            }
            else
            {
                if (i == n || id[i + 1] <= id[j + 1])
                    g[j][i] = -1;
                else
                    g[j][i] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> b[i];
        if (~b[i])
        {
            int x = a[i - 1],y = a[i];
            for (int j = 1; j <= b[i]; j++,x++,y++)
                g[x][y] = g[y][x] = 0;
            if (x <= n && y <= n)
            {
                if (g[x][y] != 1)
                    g[x][y] = -1;
                else
                    g[y][x] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] != 1)
                e[j].push_back({i,g[i][j]});
    auto dis = spfa(0);
    int _min = inf;
    for (int i = 1; i <= n; i++)
        _min = min(_min,dis[i]);
    for (int i = 1; i <= n; i++)
        cout << char(dis[i] - _min + 'a');
    return 0;
}