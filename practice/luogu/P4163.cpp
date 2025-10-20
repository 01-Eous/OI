#include<bits/extc++.h>
using namespace std;
int n,d;
string str;
int dp[1030][1005],fac[11],buc[10];
void solve()
{
    cin >> str >> d;
    memset(buc,0,sizeof(buc));
    memset(dp,0,sizeof(dp));
    for (auto &ch : str)
    {
        ch -= '0';
        buc[ch]++;
    }
    n = str.length();
    dp[0][0] = 1;
    for (int s = 0; s < 1 << n; s++)
        for (int i = 0; i < d; i++)
            for (int j = 0; j < n; j++)
                if (!(s >> j & 1))
                    dp[s | 1 << j][(i * 10 + str[j]) % d] += dp[s][i];
    int ans = dp[(1 << n) - 1][0];
    for (int i = 0; i < 10; i++)
        ans /= fac[buc[i]];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 10; i++)
        fac[i] = fac[i - 1] * i;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}