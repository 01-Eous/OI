#include<bits/extc++.h>
#define int long long
using namespace std;
int n,l,r,k;
void solve()
{
    scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
    if (n & 1)
        return (void)printf("%lld\n",l);
    if (n == 2 || r < (2LL << __lg(l)))
        return (void)puts("-1");
    if (k <= n - 2)
        printf("%lld\n",l);
    else
        printf("%lld\n",2LL << __lg(l));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}