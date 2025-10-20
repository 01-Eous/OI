#include<bits/extc++.h>
#define int long long
using namespace std;
using ld = long double;
const int maxn = 2e5 + 5;
const ld eps = 1e-12;
int n;
ld c[maxn];
int a[maxn],b[maxn],ans[maxn];
void solve()
{
    scanf("%lld",&n);
    memset(ans,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i);
    for (int i = 1; i <= n; i++)
        c[i] = (ld)a[i] / b[i];
    int x = 1,y = 0;
    for (int i = 2; i <= n; i++)
    {
        if (fabs(c[1] - c[i]) > eps)
        {
            y = i;
            break;
        }
    }
    if (!y)
        return (void)puts("No");
    if (c[x] < c[y])
    {
        ans[x] = -(a[y] + b[y]);
        ans[y] = a[x] + b[x];
    }
    else
    {
        ans[x] = a[y] + b[y];
        ans[y] = -(a[x] + b[x]);
    }
    puts("Yes");
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i]);
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