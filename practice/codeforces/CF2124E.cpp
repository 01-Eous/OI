#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 5;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i),sum += a[i];
    if (sum & 1)
        return (void)puts("-1");
    int d = 0,e,p = 0;
    while (d + a[p + 1] <= sum >> 1)
        d += a[++p];
    if (d == sum >> 1)
    {
        puts("1");
        for (int i = 1; i <= n; i++)
            printf("%lld%c",a[i]," \n"[i == n]);
        return;
    }
    e = sum - d - a[++p];
    int t1 = (d + a[p] - e) >> 1;
    int t2 = (e + a[p] - d) >> 1;
    if (d < t1 || e < t2)
        return (void)puts("-1");
    puts("2");
    for (int i = 1; i < p; i++)
        printf("%lld ",a[i]);
    printf("%lld ",t1);
    sum = e - t2;
    for (int i = p + 1; i <= n; i++)
    {
        int tmp = min(a[i],sum);
        printf("%lld%c",tmp," \n"[i == n]);
        a[i] -= tmp,sum -= tmp;
    }
    for (int i = 1; i < p; i++)
        printf("0 ");
    printf("%lld ",t2);
    for (int i = p + 1; i <= n; i++)
        printf("%lld%c",a[i]," \n"[i == n]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}