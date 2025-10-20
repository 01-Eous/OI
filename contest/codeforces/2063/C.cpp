#include<bits/extc++.h>
#define endl '\n'
using namespace std;
int n;
vector<int>son,fa;
vector<vector<int>>g;
void dfs(int u,int pre)
{
    fa[u] = pre;
    for (auto v : g[u])
    {
        if (v == pre)
            continue;
        son[u]++;
        dfs(v,u);
    }
}
void solve()
{
    cin >> n;
    g.clear();
    g.resize(n + 5);
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 2)
    {
        cout << "0\n";
        return;
    }
    son.clear();
    son.resize(n + 5);
    fa.clear();
    fa.resize(n + 5);
    dfs(1,114514);
    int x,y,max1,max2;
    x = y = 0;
    max1 = max2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (son[i] > max1)
        {
            max2 = max1;
            y = x;
            max1 = son[i];
            x = i;
        }
        else if (son[i] == max1)
        {
            if (son[i] > max2)
            {
                max2 = son[i];
                y = i;
            }
            else if (son[i] == max2 && (((fa[i] != x && fa[x] != i) || x == 1 || y == 1)))
            {
                max2 = son[i];
                if (x == 1)
                    x = i;
                else if (y == 1)
                    y = i;
            }
        }
    }
    int ans = max1 + max2 + (fa[x] != y && fa[y] != x);
    if (x == 1 || y == 1)
        ans--;
    cout << ans << endl;
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