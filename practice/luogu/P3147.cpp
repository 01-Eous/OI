#include<bits/extc++.h>
using namespace std;
const int maxn = 262144 + 5;
int n;
int dp[maxn][65];
signed main()
{
    scanf("%d",&n);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        dp[i][x] = i + 1;
    }
    int ans = 0;
    for (int j = 2; j <= 60; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!dp[i][j])
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            if (dp[i][j])
                ans = max(ans,j);
        }
    }
    printf("%d",ans);
    return 0;
}