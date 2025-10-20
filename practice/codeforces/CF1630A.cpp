#include<bits/extc++.h>
#define int long long 
using namespace std;
int n,a,b;
void solve()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    if (a == 1)
    {
        if ((n - 1) % b == 0)
            puts("Yes");
        else
            puts("No");
        return;
    }
    for (int tmp = 1; tmp <= n; tmp *= a)
        if (tmp % b == n % b)
            return (void)puts("Yes");
    puts("No");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}