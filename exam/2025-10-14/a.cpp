#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;
int n;
char s[maxn];
bool a[maxn];
int lst[2],dp[maxn],sum[maxn];
void solve()
{
    cin >> (s + 1);
    n = strlen(s + 1) - 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] ^ (s[i] == '1');
    lst[0] = lst[1] = 0;
    sum[0] = dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = sum[i - 1];
        if (lst[a[i]])
            dp[i] = (dp[i] - sum[lst[a[i]] - 1] + mod) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        lst[a[i]] = i;
    }
    cout << sum[n] << '\n';
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