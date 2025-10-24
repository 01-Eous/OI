#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,idx;
bool mp[105][105];
int a[105],dp[105],deg[105];
vector<int> g[105];
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        a[u] = ++idx;
        for (int v : g[u])
            if (!--deg[v])
                q.push(v);
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
        if (u > v)
            swap(u,v);
        mp[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (mp[i][j])
                g[j].push_back(i),deg[i]++;
            else
                g[i].push_back(j),deg[j]++;
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
    {
        int max1 = 0;
        for (int j = i - 1; j; j--)
        {
            if (a[j] < a[i] && a[j] > max1)
            {
                max1 = a[j];
                dp[i] += dp[j];
            }
        }
        if (!dp[i])
            dp[i] = 1;
    }
    int max1 = 0,ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] > max1)
        {
            max1 = a[i];
            ans += dp[i];
        }
    }
    cout << ans << '\n';
    return 0;
}