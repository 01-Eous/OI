#include<bits/extc++.h>
using namespace std;
using ld = double;
const int maxn = 1 << 20 | 5;
int n,m;
ld p[25],dp[maxn];
void solve()
{
    for (int i = 1; i <= n; i++)
        scanf("%lf",p + i);
    m = (1 << n) - 1;
    dp[m] = 0;
    for (int s = m - 1; ~s; s--)
    {
        ld sum = dp[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!((s >> (i - 1)) & 1))
            {
                dp[s] += dp[s | (1 << (i - 1))] * p[i];
                sum += p[i];
            }
        }
        dp[s] = (dp[s] + 1) / sum;
    }
    printf("%.6lf\n",dp[0]);
}
signed main()
{
    while (scanf("%d",&n) != EOF)
        solve();
    return 0;
}