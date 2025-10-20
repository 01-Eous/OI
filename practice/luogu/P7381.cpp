#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,k;
int dp[505][505];
int p[505],b[505];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int l = 0; l <= j; l++)
                dp[i][j] = max(dp[i][j],dp[i - 1][l] + b[p[i] + j - l]);
    cout << dp[n][k];
    return 0;
}