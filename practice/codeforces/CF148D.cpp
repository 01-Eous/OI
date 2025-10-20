#include<bits/extc++.h>
using namespace std;
typedef long double ld;
int w,b;
ld dp[1005][1005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> b;
    for (int i = 1; i <= w; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= b; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] += (ld)i / (i + j);
            if (i >= 1 && j >= 2)
                dp[i][j] += (ld)j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
            if (j >= 3)
                dp[i][j] += (ld)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
        }
    }
    cout << fixed << setprecision(10) << dp[w][b];
    return 0;
}