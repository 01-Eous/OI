#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
void solve()
{
    cin >> n;
    int max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        max1 = max(max1,a[i]);
        if (!(i & 1))
            a[i] = max1;
    }
    a[0] = a[n + 1] = inf;
    int ans = 0;
    for (int i = 1; i <= n; i += 2)
        ans += max(0LL,a[i] - min(a[i - 1],a[i + 1]) + 1);
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