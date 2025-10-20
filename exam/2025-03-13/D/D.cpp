#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
int n;
int a[1000],siz[1000],dp[1000][1000][2];
void dfs(int rt)
{
    if (rt > n)
    {
        dp[rt][0][0] = 0;
        return;
    }
    siz[rt] = 1;
    dfs(ls),dfs(rs);
    siz[rt] += siz[ls] + siz[rs];
    for (int i = 0; i <= siz[ls]; i++)
    {
        for (int j = 0; j <= siz[rs]; j++)
        {
            dp[rt][i + j][0] = max(dp[rt][i + j][0],max(dp[ls][i][0] + a[ls],dp[ls][i][1]) + max(dp[rs][j][0] + a[rs],dp[rs][j][1]));
            dp[rt][i + j + 1][1] = max(dp[rt][i + j + 1][1],max(dp[ls][i][1] + a[ls],dp[ls][i][0]) + max(dp[rs][j][1] + a[rs],dp[rs][j][0]));
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    memset(dp,~0x3f,sizeof dp);
    dfs(1);
    printf("%lld",max(dp[1][n >> 1][0],dp[1][n >> 1][1]));
    return 0;
}