#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,a[maxn];
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans = (ans + a[i] * Inv(a[1] + a[i])) % mod;
    printf("%lld",ans);
    return 0;
}