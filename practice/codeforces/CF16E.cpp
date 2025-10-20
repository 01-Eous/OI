#include<bits/extc++.h>
using namespace std;
typedef double ld;
const int maxn = 1 << 18 | 5;
int n;
ld a[20][20],dp[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dp[(1 << n) - 1] = 1;
    for (int k = (1 << n) - 2; k > 0; k--)
        for (int i = 1; i <= n; i++)
            if (k & (1 << (i - 1)))
                for (int j = 1; j <= n; j++)
                    if (int cnt = __popcount(k); ~k & (1 << (j - 1)))
                        dp[k] += dp[k | (1 << (j - 1))] * a[i][j] * 1.0 / ((cnt + 1) * cnt / 2.0);
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(6) << dp[1 << (i - 1)] << ' ';
    return 0;
}