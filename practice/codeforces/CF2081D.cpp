#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
int a[maxn],fa[maxn];
vector<array<int,3>> e;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void solve()
{
    e.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    n = unique(a + 1,a + n + 1) - a - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= a[n]; j += a[i])
        {
            int p = lower_bound(a + 1,a + n + 1,j) - a;
            if (p == i)
                p = upper_bound(a + 1,a + n + 1,j) - a;
            if (p > n)
                break;
            e.push_back({a[p] % a[i],i,p});
        }
    }
    sort(e.begin(),e.end());
    iota(fa + 1,fa + n + 1,1);
    int ans = 0;
    for (auto [w,u,v] : e)
    {
        u = find(u),v = find(v);
        if (u != v)
        {
            ans += w;
            fa[u] = v;
        }
    }
    cout << ans << '\n';
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