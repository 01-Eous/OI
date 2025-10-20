#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m,ans;
int u[maxn],v[maxn];
int id[maxn],in[maxn];
bitset<450> s[450];
vector<int> g[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        in[u[i]]++,in[v[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (in[u[i]] < in[v[i]])
            g[u[i]].push_back(v[i]);
        else
            g[v[i]].push_back(u[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int idx = 0;
        for (auto j : g[i])
            id[j] = ++idx;
        for (auto j : g[i])
            for (auto k : g[j])
                if (id[k])
                    s[id[j]][id[k]] = 1;
        for (auto j : g[i])
            for (auto k : g[j])
                if (id[k])
                    ans += (s[id[j]] & s[id[k]]).count();
        for (auto j : g[i])
        {
            s[id[j]].reset();
            id[j] = 0;
        }
    }
    cout << ans;
    return 0;
}