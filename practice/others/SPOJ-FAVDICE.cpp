#include<bits/extc++.h>
using namespace std;
int n;
double dp[1005];
void solve()
{
    scanf("%d",&n);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        dp[i] = dp[i + 1] + (double)n / (n - i);
    printf("%.2lf\n",dp[0]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}