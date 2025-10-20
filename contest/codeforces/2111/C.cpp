#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j < n && a[j + 1] == a[i])
            j++;
        ans = min(ans,a[i] * (i - 1 + n - j));
        i = j;
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