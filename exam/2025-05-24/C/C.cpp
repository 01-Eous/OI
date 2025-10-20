#include<bits/extc++.h>
using namespace std;
using ld = long double;
int n,m,x,y,s;
ld sum1[5005],sum2[5005];
ld dp1[2][1005],dp2[2][1005];
signed main()
{
    cin >> n >> m >> x >> y >> s;
    x++,y++;
    dp1[0][x] = sum1[0] = 1;
    for (int i = 1; i <= s; i++)
    {
        int cur = i & 1,lst = cur ^ 1;
        for (int j = 1; j <= n; j++)
        {
            dp1[cur][j] = 0.5 * (dp1[lst][j + 1] + dp1[lst][j - 1]);
            sum1[i] += dp1[cur][j];
        }
    }
    dp2[0][y] = sum2[0] = 1;
    for (int i = 1; i <= s; i++)
    {
        int cur = i & 1,lst = cur ^ 1;
        for (int j = 1; j <= m; j++)
        {
            dp2[cur][j] = 0.5 * (dp2[lst][j + 1] + dp2[lst][j - 1]);
            sum2[i] += dp2[cur][j];
        }
    }
    ld Nahida = 1,ans = 0;
    for (int i = 1; i <= s; i++)
        Nahida /= 2.0;
    for (int i = 0; i <= s; i++)
    {
        ld Klee = Nahida;
        for (int j = 0; j < i; j++)
            Klee = Klee * (s - j) / (j + 1);
        ans += Klee * sum1[i] * sum2[s - i];
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}