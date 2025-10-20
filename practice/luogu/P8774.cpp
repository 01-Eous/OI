#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n;
int p[maxn];
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
signed main()
{
    scanf("%lld",&n);
    for (int i = 1,x,y; i <= n; i++)
    {
        scanf("%lld%lld",&x,&y);
        p[i] = x * inv(y) % mod;
    }
    int s1 = 1,s2 = 0,s3 = 0;
    for (int i = 1; i <= n; i++)
    {
        s3 = (s3 + s1) % mod;
        s2 = (s2 + s1 * p[i]) % mod;
        s1 = s1 * (1 - p[i] + mod) % mod;
    }
    printf("%lld",s3 * inv(1 - s2 + mod) % mod);
    return 0;   
}