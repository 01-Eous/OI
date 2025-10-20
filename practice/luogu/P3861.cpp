#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,idx;
int a[6725],dp[6725][6725];
unordered_map<int,int> pos;
void solve()
{
    cin >> n;
    idx = 0,pos.clear();
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i)
            continue;
        a[++idx] = i;
        if (n / i != i)
            a[++idx] = n / i;
    }
    sort(a + 1,a + idx + 1);
    for (int i = 1; i <= idx; i++)
        pos[a[i]] = i;
    dp[1][1] = 1;
    for (int i = 1; i <= idx; i++)
        for (int j = 2; j <= idx; j++)
            if (dp[i][j] = dp[i][j - 1]; a[i] % a[j] == 0)
                dp[i][j] = (dp[i][j] + dp[pos[a[i] / a[j]]][j - 1]) % mod;
    cout << dp[idx][idx] - 1 << '\n';
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