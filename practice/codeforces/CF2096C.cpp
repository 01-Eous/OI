#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
int a[1005],b[1005];
int h[1005][1005],dp[1005][2];
void 转圈圈()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            swap(h[i][j],h[j][i]);
}
int calc(int a[])
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i][1] = inf;
    dp[1][0] = 0,dp[1][1] = a[1];
    for (int i = 1; i <= n; i++)
    {
        for (int u = 0; u < 2; u++)
        {
            for (int v = 0; v < 2; v++)
            {
                bool flag = 1;
                for (int j = 1; j <= n; j++)
                    flag &= (h[i - 1][j] + v != h[i][j] + u);
                if (flag)
                    dp[i][u] = min(dp[i][u],dp[i - 1][v] + u * a[i]);
            }
        }
    }
    return min(dp[n][0],dp[n][1]);
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld",h[i] + j);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int j = 1; j <= n; j++)
        scanf("%lld",b + j);
    int ans1 = calc(a);
    转圈圈();
    int ans = ans1 + calc(b);
    printf("%lld\n",ans < inf ? ans : -1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}