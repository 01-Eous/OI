#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,s;
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&s);
    if (n > 2e9)
        return (void)puts("0");
    if (s < (__int128)n * (n + 1) / 2)
        return (void)puts("0");
    if (s > (__int128)m * n * (n + 1) / 2)
        return (void)puts("0");
    puts("1");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}