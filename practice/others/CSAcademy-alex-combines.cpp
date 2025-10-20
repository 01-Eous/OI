#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
int n,q;
int a[maxn],lst[maxm],f[maxn],dp[25][maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    fill(lst + 1,lst + (int)1e6 + 1,n + 1);
    f[n + 1] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        f[i] = min(f[i + 1],lst[a[i]]);
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        dp[0][i] = f[i];
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
    scanf("%d",&q);
    int l,r;
    while (q--)
    {
        scanf("%d%d",&l,&r);
        int ans = 1;
        for (int i = 20; ~i; i--)
        {
            if (dp[i][l] && dp[i][l] <= r)
            {
                l = dp[i][l];
                ans += 1 << i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}