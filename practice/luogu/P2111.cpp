#include<bits/extc++.h>
using namespace std;
int n,m;
char s[10005];
double dp[55][55],a;
signed main()
{
    scanf("%d%lf%d%s",&n,&a,&m,s + 1);
    if (n > 50)
        return printf("1.000"),0;
    a /= 100.0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (s[i] == '1')
                dp[i][j] += dp[i - 1][j] * (1 - a) + (!j ? 0 : dp[i - 1][j - 1] * a);
            else
                dp[i][j] += dp[i - 1][j] * a + (!j ? 0 : dp[i - 1][j - 1] * (1 - a));
        }
    }
    double ans = 0;
    for (int i = m; i <= n; i++)
        ans += dp[n][i];
    printf("%.3lf",ans);
    return 0;
}