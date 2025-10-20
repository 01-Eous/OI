#include<bits/extc++.h>
using namespace std;
const int maxn = 1 << 18 | 5;
int n,m;
int a[20];
void solve()
{
    scanf("%d",&n);
    m = (1 << n) - 1;
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int k = 1; k < m; k++)
    {
        int gcd1 = 0,gcd2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (k & (1 << (i - 1)))
                gcd1 = __gcd(gcd1,a[i]);
            else
                gcd2 = __gcd(gcd2,a[i]);
        }
        if (gcd1 == 1 && gcd2 == 1)
            return (void)puts("Yes");
    }
    puts("No");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}