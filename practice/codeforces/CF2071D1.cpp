#include<bits/extc++.h>
#define int long long
#define sum(x,y) (a[x - 1] ^ a[y])
using namespace std;
const int maxn = 2e5 + 5;
int n,l,r;
int a[maxn];
int dfs(int u)
{
    if (u <= n)
        return sum(u,u);
    if ((u >> 1) <= n)
        return sum(1,u >> 1);
    int ret = sum(1,n);
    if (!((u >> 1) & 1))
        ret ^= dfs(u >> 1);
    if (!(n & 1))
        ret ^= dfs(n + 1);
    return ret;
}
void solve()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    cout << dfs(l) << '\n';
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