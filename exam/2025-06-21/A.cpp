#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,sum,x;
signed main()
{
    scanf("%lld%lld",&n,&sum);
    int ans = 0;
    while (--n)
    {
        scanf("%lld",&x);
        ans = (ans + sum * x % mod * (sum + x) % mod) % mod;
        sum = (sum + x) % mod;
    }
    printf("%lld",ans);
    return 0;
}