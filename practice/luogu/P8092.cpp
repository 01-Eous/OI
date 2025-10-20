#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            int tmp = a[i] - a[i - 1];
            ans += tmp << 1;
            a[i + 1] -= tmp;
            a[i] -= tmp;
        }
        if (a[i] > a[i + 1])
        {
            int tmp = a[i] - a[i + 1];
            ans += tmp << 1;
            a[i - 1] -= tmp;
            a[i] -= tmp;
        }
    }
    for (int i = n - 1; i > 1; i--)
    {
        if (a[i] > a[i - 1])
        {
            int tmp = a[i] - a[i - 1];
            ans += tmp << 1;
            a[i + 1] -= tmp;
            a[i] -= tmp;
        }
        if (a[i] > a[i + 1])
        {
            int tmp = a[i] - a[i + 1];
            ans += tmp << 1;
            a[i - 1] -= tmp;
            a[i] -= tmp;
        }
    }
    for (int i = 1; i < n; i++)
        if (a[i] < 0 || a[i] != a[i + 1])
            return (void)(cout << "-1\n");
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