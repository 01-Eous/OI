#include<bits/extc++.h>
#define int long long
#define inf (int)1e13
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
int a[maxn];
char s[maxn];
void solve()
{
    scanf("%lld%lld%s",&n,&m,s + 1);
    int sum,max1,max2,pos = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (s[i] == '0')
        {
            pos = i;
            a[i] = -inf;
        }
    }
    sum = max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = max(0LL,sum) + a[i];
        max1 = max(max1,sum);
    }
    if (max1 == m)
        goto Nahida;
    else if (max1 > m || !pos)
        return (void)puts("No");
    sum = max1 = 0;
    for (int i = pos - 1; i >= 1; i--)
        max1 = max(max1,sum += a[i]);
    sum = max2 = 0;
    for (int i = pos + 1; i <= n; i++)
        max2 = max(max2,sum += a[i]);
    a[pos] = m - max1 - max2;
    Nahida:
    puts("Yes");
    for (int i = 1; i <= n; i++)
        printf("%lld ",a[i]);
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