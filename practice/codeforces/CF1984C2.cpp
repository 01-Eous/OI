#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
int p2[maxn << 1],a[maxn];
void solve()
{
    cin >> n;
    int _min = inf,ans = 0,cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        _min = min(_min,a[i]);
    }
    if (_min >= 0)
    {
        cout << p2[n] << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 0)
            cnt++;
        else if (a[i] == _min)
            ans = (ans + p2[cnt + n - i]) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p2[0] = 1;
    for (int i = 1; i <= 4e5; i++)
        p2[i] = (p2[i - 1] << 1) % mod;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}