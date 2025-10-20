#include<bits/extc++.h>
using namespace std;
const int maxn = 1005;
int n,m;
int fa[maxn];
bool apr[maxn];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void solve()
{
    cin >> m;
    iota(fa + 1,fa + n + 1,1);
    fill(apr + 1,apr + n + 1,0);
    int u,v,cnt = 0;
    while (m--)
    {
        cin >> u >> v;
        u = find(u),v = find(v);
        if (u != v)
            fa[u] = v;
    }
    for (int i = 1; i <= n; i++)
    {
        int f = find(i);
        if (!apr[f])
        {
            apr[f] = 1;
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n,n)
        solve();
    return 0;
}