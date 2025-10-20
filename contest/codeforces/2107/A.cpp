#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int a[105],b[105];
void solve()
{
    scanf("%lld",&n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum = __gcd(sum,b[i] = a[i]);
    }
    sort(a + 1,a + n + 1);
    if (a[1] == a[n])
        return (void)puts("No");
    puts("Yes");
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == a[n])
            printf("1 ");
        else
            printf("2 ");
    }
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}