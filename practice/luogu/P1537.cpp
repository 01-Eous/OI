#include<bits/extc++.h>
using namespace std;
int n = 6,sum;
int cnt[8];
void solve()
{
    bitset<(int)2e5 + 5>dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= cnt[i]; k++)
            dp |= dp << (k * i);
    cout << (((sum & 1) == 0 && dp[sum >> 1]) ? "Can be divided.\n" : "Can't be divided.\n") << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt[i];
        sum += cnt[i] * i;
    }
    while (sum)
    {
        cout << "Collection #" << ++t << ":\n";
        solve();
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> cnt[i];
            sum += cnt[i] * i;
        }
    }
    return 0;
}