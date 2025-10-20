#include<bits/extc++.h>
using namespace std;
int n,idx;
int l[505],r[505];
int ans[505],in[505];
vector<int> g[505];
void topsort()
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        ans[u] = idx--;
        for (auto v : g[u])
            if (!--in[v])
                q.push(v);
    }
}
void solve()
{
    cin >> n;
    idx = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        g[i].clear(),in[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (l[i] < l[j] && r[j] < r[i])
            {
                in[j]++;
                g[i].push_back(j);
            }
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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