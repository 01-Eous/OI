#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,mod;
signed main()
{
    scanf("%lld%lld%lld",&a,&b,&mod);
    if (a % mod > b % mod || b - a + 1 >= mod)
        printf("%lld",mod - 1);
    else
        printf("%lld",max(a % mod,b % mod));
    return 0;
}