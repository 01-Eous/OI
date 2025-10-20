#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
int n;
int a[maxn];
int lst[maxn],apr[maxm];
int sum[maxn],dp[maxn][2];
void clear()
{
    memset(lst,0,sizeof lst);
    memset(apr,0,sizeof apr);
    memset(sum,0,sizeof sum);
    memset(dp,0,sizeof dp);
}
void solve()
{
    clear();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        lst[i] = apr[a[i]];
        apr[a[i]] = i;
        sum[i] = sum[i - 1] + (a[i] == a[i - 1]) * a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!lst[i])
            goto Nahida;
        if (lst[i] != i - 1)
        {
            dp[i][0] = a[i] + dp[lst[i] + 1][0] + sum[i - 1] - sum[lst[i] + 1];
            dp[i][1] = a[i] + dp[lst[i] + 1][1] + sum[i - 1] - sum[lst[i] + 1];
        }
        else
        {
            dp[i][0] = dp[i - 1][0] + a[i];
            dp[i][1] = dp[i - 1][1] + a[i];
        }
        Nahida:if (lst[i] != i - 1)
        {
            dp[i][0] = max({dp[i][0],dp[i - 1][0],dp[i - 1][1]});
            dp[i][1] = max({dp[i][1],dp[i - 1][0],dp[i - 1][1]});
        }
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}