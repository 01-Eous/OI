#include<iostream>
#include<iomanip>
using namespace std;
int n,s;
double dp[1005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    dp[n][s] = 0;
    for (int i = n; i >= 0; i--)
        for (int j = s; j >= 0; j--)
            if (i != n || j != s)
                dp[i][j] += (n * s + i * (s - j) * dp[i][j + 1] + (n - i) * j * dp[i + 1][j] + (n - i) * (s - j) * dp[i + 1][j + 1]) / (n * s - i * j);
    cout << fixed << setprecision(4) << dp[0][0];
    return 0;
}