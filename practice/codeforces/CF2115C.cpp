#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,sum,min1,a[25];
double p,dp1[4005][4005],dp2[4005][25][405];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void clear()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
            dp1[i][j] = 0;
        for (int k = 0; k < n; k++)
            for (int j = 0; j <= min1; j++)
                dp2[i][k][j] = 0;
    }
}
void solve()
{
    n = read(),m = read(),p = read() / 100.0;
    min1 = inf,sum = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read() - 1;
        min1 = min(min1,a[i]);
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i] - min1;
    if (sum > m)
        return (void)puts("0.00000000");
    clear();
    dp1[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            dp1[i + 1][j] += dp1[i][j] * p;
            dp1[i + 1][j + 1] += dp1[i][j] * (1 - p);
        }
    }
    dp2[0][0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        dp2[i][0][0] = 1;
        for (int j = 1; j <= min1; j++)
            dp2[i][0][j] = dp2[i - 1][0][j - 1] * p + max(dp2[i - 1][0][j],dp2[i - 1][n - 1][j - 1]) * (1 - p);
        for (int k = 1; k < n; k++)
        {
            dp2[i][k][0] = dp2[i - 1][k][0] * p + dp2[i - 1][k - 1][0] * (1 - p);
            for (int j = 1; j <= min1; j++)
                dp2[i][k][j] = dp2[i - 1][k][j - 1] * p + dp2[i - 1][k - 1][j] * (1 - p);
        }
    }

    double ans = 0;
    for (int i = sum; i <= m; i++)
    {
        double max1 = 0;
        for (int j = 0; j <= min(i - sum,min1); j++)
            max1 = max(max1,dp2[m - i][0][min1 - j]);
        ans += dp1[i][sum] * max1;
    }
    printf("%.8lf\n",ans);
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}