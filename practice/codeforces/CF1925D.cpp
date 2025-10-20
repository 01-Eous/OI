#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 1e9 + 7;
int n,m,k;
int ans,sum,p;
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    p = 2 * inv(n * (n - 1) % mod) % mod;
    ans = sum = 0;
    int u,v,w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        sum = (sum + w) % mod;
    }
    while (k--)
    {
        ans = (ans + sum * p) % mod;
        sum = (sum + m * p) % mod;
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}