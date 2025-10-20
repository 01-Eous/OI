#include<bits/extc++.h>
using namespace std;
typedef double ld;
const ld eps = 1e-9;
int n,q;
ld dp[20005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    dp[0][0] = 1;
    for (int i = 1; i <= 2e4; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] * j / n + dp[i - 1][j - 1] * (n - j + 1) / n;
    ld x;
    while (q--)
    {
        cin >> x;
        x /= 2000.0;
        for (int i = 1; i <= 2e4; i++)
        {
            if (dp[i][n] - x > eps)
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}