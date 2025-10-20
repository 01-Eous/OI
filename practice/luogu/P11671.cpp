#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 4e5 + 5;
int n,mod;
int a[maxn],sum[maxn];
void solve()
{
    cin >> n >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= mod;
    }
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i] + mod;
    for (int i = 1; i <= n << 1; i++)
        sum[i] = sum[i - 1] + a[i];
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        int pos = i - 1 + (n >> 1) + (n & 1);
        ans = min(ans,
            (pos - i) * a[pos] - (sum[pos - 1] - sum[i - 1]) + 
            (sum[i + n - 1] - sum[pos]) - (i + n - pos - 1) * a[pos]
        );
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