#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n;
int dp[maxn][2];
int &add(int &x,const int &y)
{
    x += y;
    if (x >= mod) x -= mod;
    return x;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 1)
        return cout << "1\n",0;
    if (n == 2)
        return cout << "2\n",0;
    dp[1][0] = dp[2][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = i - 1; k <= n; k += i - 1)
            {
                if (k > i)
                    add(dp[k][j ^ 1],dp[i][j]);
                if (k + 1 > i && i > 2)
                    add(dp[k + 1][j ^ 1],dp[i][j]);
                if (k + 2 > i && i > 3)
                    add(dp[k + 2][j ^ 1],dp[i][j]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
        add(ans,dp[i][0] + dp[i][1]);
    cout << ans * n % mod << '\n';
    return 0;
}