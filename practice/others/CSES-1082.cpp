#include<bits/extc++.h>
#define int long long
using namespace std;
using i128 = __int128_t;
const int mod = 1e9 + 7;
int n;
signed main()
{
    scanf("%lld",&n);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = min(n,n / (n / l));
        i128 tmp = (i128)(r - l + 1) * (l + r) >> 1;
        ans = (ans + tmp % mod * (n / l) % mod) % mod;
    }
    printf("%lld",ans);
    return 0;
}