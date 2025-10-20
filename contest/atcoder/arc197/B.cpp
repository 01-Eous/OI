#include<bits/extc++.h>
#define chk1(mid) a[mid] > (sum + a[mid]) / (i + 1)
#define chk2(mid) a[res] > (sum + pre[mid] - pre[res - 1]) / (i + mid - res + 1)
using namespace std;
const int maxn = 2e5 + 5;
using ll = long long;
int n;
ll a[maxn],pre[maxn];
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    ll sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        int l = i + 1,r = n,mid,res = 0,tmp = 0;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (chk1(mid))
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (!res)
            continue;
        l = res,r = n;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (chk2(mid))
            {
                tmp = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (tmp)
            ans = max(ans,tmp - res + 1);
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}