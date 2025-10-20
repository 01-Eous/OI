#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m,mod;
int dp1[maxn],dp2[350][maxn];
signed main()
{
    scanf("%lld%lld",&n,&mod);
    m = sqrt(n) + 1,dp1[0] = 1;
    for (int i = 1; i < m; i++)
        for (int j = i; j <= n; j++)
            dp1[j] = (dp1[j] + dp1[j - i]) % mod;
    dp2[0][0] = 1;
    for (int i = 1; i < m; i++)
        for (int j = max(i,m); j <= n; j++)
            dp2[i][j] = (dp2[i][j - i] + dp2[i - 1][j - m]) % mod;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
            tmp = (tmp + dp2[j][n - i]) % mod;
        ans = (ans + dp1[i] * tmp) % mod;
    }
    printf("%lld",ans);
    return 0;
}