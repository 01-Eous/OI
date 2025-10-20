#include<bits/extc++.h>
using namespace std;
int n,m,k;
vector<bool>add;
vector<int>in,ans;
vector<vector<int>>g;
priority_queue<int,vector<int>,greater<int>>q1;
priority_queue<int,vector<int>,less<int>>q2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    add.resize(n + 5),in.resize(n + 5),g.resize(n + 5);
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q1.push(i);
    int cnt = 0;
    while (ans.size() < n)
    {
        if (q1.empty())
        {
            int u = q2.top();
            q2.pop();
            for (auto v : g[u])
            {
                in[v]--;
                if (in[v] == 0)
                    q1.push(v);
            }
            ans.push_back(u);
            continue;
        }
        int u = q1.top();
        q1.pop();
        if (cnt == k)
        {
            for (auto v : g[u])
            {
                in[v]--;
                if (in[v] == 0)
                    q1.push(v);
            }
            ans.push_back(u);
            continue;
        }
        if (!q1.empty())
        {
            add[u] = 1;
            cnt++;
            q2.push(u);
            continue;
        }
        if (q2.empty())
        {
            for (auto v : g[u])
            {
                in[v]--;
                if (in[v] == 0)
                    q1.push(v);
            }
            ans.push_back(u);
            continue;
        }
        int v = q2.top();
        if (v < u)
        {
            for (auto v : g[u])
            {
                in[v]--;
                if (in[v] == 0)
                    q1.push(v);
            }
            ans.push_back(u);
            continue;
        }
        q2.pop();
        q2.push(u),q1.push(v);
        add[u] = 1,cnt++;
    }
    for (auto i : ans)
        cout << i << " ";
    // cout << '\n' << cnt << '\n';
    // for (auto i = ans.begin() + 1; i != ans.end(); i++)
    //     if (add[*i])
    //         cout << *(i - 1) << " " << *i << '\n';
    return 0;
}