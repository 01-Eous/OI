#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
bool fl[maxn];
int a[maxn],buc[maxn],dp[maxn];
void solve()
{
    scanf("%lld",&n);
    memset(dp,0,sizeof(int) * (n + 5));
    memset(fl,0,sizeof(bool) * (n + 5));
    memset(buc,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        buc[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (buc[i])
            for (int j = i; j <= n; j += i)
                fl[j] = 1;
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j += i)
            dp[i] += buc[j];
        dp[i] = dp[i] * (dp[i] - 1) >> 1;
        for (int j = i << 1; j <= n; j += i)
            dp[i] -= dp[j];
        ans += (!fl[i]) * dp[i];
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}