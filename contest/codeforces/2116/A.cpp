#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,c,d;
void solve()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if (min(a,c) >= min(b,d))
        puts("Gellyfish");
    else
        puts("Flower");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}