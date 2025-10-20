#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int dp[maxn],in[maxn];
vector<int> g[maxn];
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            dp[v] = max(dp[v],dp[u] + 1);
            if (!--in[v])
                q.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u,v;
    while (m--)
    {
        cin >> u >> v;
        in[v]++;
        g[u].push_back(v);
    }
    topsort();
    for (int i = 1; i <= n; i++)
        cout << dp[i] << '\n';
    return 0;
}