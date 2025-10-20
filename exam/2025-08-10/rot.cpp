#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 998244353;
int n,m;
int a[5005],dp[5005][5005];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    reverse(a + 1,a + n + 1);
    a[0] = inf,dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])
            break;
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            add(dp[i + 1][j + 1],dp[i][j]);
            add(dp[i + 1][j],dp[i][j] * (n - j));
        }
    }
    printf("%lld",dp[m][n]);
    return 0;
}