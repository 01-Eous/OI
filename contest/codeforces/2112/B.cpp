#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[1005];
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    a[0] = -1;
    bool f1 = 1,f2 = 1,fl = 0;
    for (int i = 1; i <= n; i++)
    {
        f1 &= a[i] > a[i - 1];
        f2 &= a[i] > a[i + 1];
        fl |= abs(a[i] - a[i - 1]) <= 1;
    }
    if (fl)
        puts("0");
    else if (!f1 && !f2)
        puts("1");
    else
        puts("-1");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}