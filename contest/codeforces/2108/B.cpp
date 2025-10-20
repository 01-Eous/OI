#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
void solve()
{
    scanf("%lld%lld",&n,&k);
    if (n == 1 && !k)
        return (void)puts("-1");
    if (__popcount(k) >= n)
        return (void)printf("%lld\n",k);
    int cnt = n - __popcount(k),sum = k + cnt;
    if (cnt & 1)
    {
        if (k <= 1)
            sum += 3;
        else
            sum += 1;
    }
    printf("%lld\n",sum);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}