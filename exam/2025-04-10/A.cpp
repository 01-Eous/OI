#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k,s,sum;
int a[105];
inline int chk(int x)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i] % x;
    return res;
}
inline void solve()
{
    scanf("%lld%lld",&n,&s);
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum += a[i];
    }
    k = sum - s;
    if (!k)
        return (void)puts("YES");
    for (int i = 1; i * i <= k; i++)
        if (k % i == 0 && (chk(i) == s || chk(k / i) == s))
            return (void)puts("YES");
    puts("NO");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    fprintf(stderr,"%.3lf",clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
