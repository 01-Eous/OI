#include<bits/extc++.h>
using namespace std;
int n;
int a[805];
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt1 = 0,cnt2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if (__gcd(a[i],a[j]) == 1)
                    cnt1++;
                else
                    cnt2++;
            }
        }
        ans += cnt1 * cnt2;
    }
    ans = n * (n - 1) * (n - 2) / 6 - ans / 2;
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