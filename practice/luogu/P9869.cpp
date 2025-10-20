#include<bits/extc++.h>
#define True (n + 1)
#define False -(n + 1)
#define Unknown 0
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int fa[maxn];
bool vis[maxn << 1];
int find(int u)
{
    int res;
    if (u == True || u == False)
        return u;
    if (u == Unknown || vis[n - u])
        return Unknown;
    if (vis[n + u])
        return True;
    if (u < 0)
    {
        if (u == -fa[-u])
            return u;
        vis[n + u] = 1;
        res = find(-fa[-u]);
        vis[n + u] = 0;
    }
    else
    {
        if (u == fa[u])
            return u;
        vis[n + u] = 1;
        res = fa[u] = find(fa[u]);
        vis[n + u] = 0;
    }
    return res;
}
void solve()
{
    cin >> n >> m;
    iota(fa + 1,fa + n + 1,1);
    char op;
    int x,y;
    while (m--)
    {
        cin >> op >> x;
        if (op == 'T')
            fa[x] = True;
        else if (op == 'F')
            fa[x] = False;
        else if (op == 'U')
            fa[x] = Unknown;
        else
        {
            cin >> y;
            if (op == '+')
                fa[x] = fa[y];
            else
                fa[x] = -fa[y];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += find(i) == Unknown;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}