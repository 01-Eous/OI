#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int l = n + 1,r = 0;
        for (int j = 1; j < i; j++)
        {
            while (l > 1 && a[l - 1] > max(a[n] - a[i] - a[j],a[i] - a[j]))
                l--;
            while (r < n && a[r + 1] < a[i] + a[j])
                r++;
            if (l <= r)
            {
                int tmp = r - l + 1;
                if (l <= i && i <= r)
                    tmp--;
                if (l <= j && j <= r)
                    tmp--;
                ans += tmp;
            }
        }
    }
    printf("%lld\n",ans / 3);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}