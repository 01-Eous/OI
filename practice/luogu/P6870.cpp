#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 1e9 + 7;
int n;
int c[355][355];
int dp[355][355][2];
void init()
{
    for (int i = 0; i <= n; i++)
        c[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n,init();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                for (int x = 0; x + j <= n; x++)
                    add(dp[i + 1][j + x][k | (x == i + 1)],dp[i][j][k] * c[n - j][x]);
    cout << dp[n][n][1];
    return 0;
}