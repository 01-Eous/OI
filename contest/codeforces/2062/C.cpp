#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int>a(n + 5);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i + 1] - a[i];
    n--;
    while (n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i];
        ans = max(ans,abs(sum));
        for (int i = 1; i < n; i++)
            a[i] = a[i + 1] - a[i];
        n--;
    }
    cout << ans << "\n";
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