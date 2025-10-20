#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn];
bool chk(int mid)
{
    int minb = inf,cnt1 = 0,cnt2 = 0;
    for (int i = 1; i <= mid; i++)
        minb = min(minb,b[i]);
    for (int i = 1; i <= n - mid + 1; i++)
        cnt1 += a[i] < minb;
    for (int i = n - mid + 2; i <= n; i++)
        cnt2 += a[i] > minb;
    return cnt1 <= 1 && cnt2 >= cnt1;
}
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d",b + i);
    int l = 1,r = n,mid,ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (!ans)
        puts("0");
    else
        printf("%d\n",n - ans + 1);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}