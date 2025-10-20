#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    int min1 = inf,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        min1 = min(min1,a[i]);
        ans += min1;
    }
    min1 = inf;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans,sum + min(min1,a[i] + a[i + 1]));
        min1 = min(min1,a[i]);
        sum += min1;
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