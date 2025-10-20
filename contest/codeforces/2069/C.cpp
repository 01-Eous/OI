#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
void solve()
{
    cin >> n;
    vector<int>a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0,ans = 0,now = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 3)
        {
            cnt++;
            now++;
        }
        else if (a[i] == 1)
            ans = (ans + now - cnt + mod) % mod;
        else
            now = (now << 1) % mod;
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