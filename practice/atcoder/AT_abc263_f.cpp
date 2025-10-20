#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1 << 16 | 5;
int n,m;
int c[maxn][20];
int dp[20][maxn];
signed main()
{
    scanf("%lld",&n);
    m = 1 << n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld",c[i] + j);
    for (int i = 1; i <= n; i++)
    {
        int len = 1 << i;
        for (int l = 1,r; (r = l + len - 1) <= m; l = r + 1)
        {
            int mid = (l + r) >> 1;
            int lft = 0,rht = 0;
            for (int j = l; j <= mid; j++)
                lft = max(lft,dp[i - 1][j]);
            for (int j = mid + 1; j <= r; j++)
                rht = max(rht,dp[i - 1][j]);
            for (int j = l; j <= mid; j++)
                dp[i][j] = dp[i - 1][j] - c[j][i - 1] + c[j][i] + rht;
            for (int j = mid + 1; j <= r; j++)
                dp[i][j] = dp[i - 1][j] - c[j][i - 1] + c[j][i] + lft;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans,dp[n][i]);
    printf("%lld",ans);
    return 0;
}