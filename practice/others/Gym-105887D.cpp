#include<bits/extc++.h>
#define int long long
#define add(x,y) (x = (x + y) % mod)
using namespace std;
const int mod = 998244353;
int n;
char s[105];
int dp[205][205][205];
signed main()
{
    scanf("%lld%s",&n,s + 1);
    int ans = 0;
    for (int p = 0; p <= 200; p++)
    {
        if (p == 100)
            continue;
        dp[0][100][100] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 200; j++)
            {
                if (abs(j - p) > n - i)
                    continue;
                for (int k = 0; k <= 200; k++)
                {
                    dp[i][j][k] = 0;
                    if (k + p - 100 == j)
                        continue;
                    bool fj1 = s[i] == 'L' || s[i] == '?';
                    bool fj2 = s[i] == 'R' || s[i] == '?';
                    bool fk1 = s[i + n] == 'L' || s[i + n] == '?';
                    bool fk2 = s[i + n] == 'R' || s[i + n] == '?';
                    if (fj1 && j < 200)
                    {
                        if (fk1 && k < 200)
                            add(dp[i][j][k],dp[i - 1][j + 1][k + 1]);
                        if (fk2 && k)
                            add(dp[i][j][k],dp[i - 1][j + 1][k - 1]);
                    }
                    if (fj2 && j)
                    {
                        if (fk1 && k < 200)
                            add(dp[i][j][k],dp[i - 1][j - 1][k + 1]);
                        if (fk2 && k)
                            add(dp[i][j][k],dp[i - 1][j - 1][k - 1]);
                    }
                }
            }
        }
        for (int i = 0; i <= 200; i++)
            add(ans,dp[n][p][i]);
    }
    printf("%lld\n",ans);
    return 0;
}