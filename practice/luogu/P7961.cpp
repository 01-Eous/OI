#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 998244353;
int n,m,q;
int c[35][35];
int v[105],pw[105][35];
int dp[105][35][35][20];
void init()
{
    for (int i = 0; i <= n; i++)
        c[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= n; j++)
            pw[i][j] = pw[i][j - 1] * v[i] % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i <= m; i++)
        cin >> v[i],pw[i][0] = 1;
    init();
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= q; k++)
                for (int p = 0; p <= n >> 1; p++)
                    for (int x = 0; x <= n - j; x++)
                        add(dp[i + 1][j + x][k + ((x + p) & 1)][(x + p) >> 1],dp[i][j][k][p] * pw[i][x] % mod * c[n - j][x]);
    int ans = 0;
    for (int k = 0; k <= q; k++)
        for (int p = 0; p <= n >> 1; p++)
            if (k + __builtin_popcountll(p) <= q)
                add(ans,dp[m + 1][n][k][p]);
    cout << ans;
    return 0;
}