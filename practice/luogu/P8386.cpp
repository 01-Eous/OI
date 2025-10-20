#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 1e9 + 7;
int n,m;
int dp[3005][3005][2];
signed main()
{
    scanf("%lld%lld",&n,&m);
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            add(dp[i][j][0],dp[i - 1][j][0] * (m - j));
            add(dp[i][j][0],dp[i - 1][j - 1][1] * (m - j + 1));
            add(dp[i][j][1],dp[i - 1][j][0] * j);
            add(dp[i][j][1],dp[i - 1][j][1] * j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        add(ans,dp[n][i][1]);
    printf("%lld",ans);
    return 0;
}