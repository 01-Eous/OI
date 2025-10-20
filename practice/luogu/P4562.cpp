#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
int l,r,n;
bool vis[maxn];
int fac[maxn],inv[maxn];
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
void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    scanf("%lld%lld",&l,&r);
    init(n = r - l + 1);
    int cnt = 0,ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (!vis[i])
        {
            cnt++;
            for (int j = i << 1; j <= r; j += i)
                vis[j] = 1;
        }
    }
    for (int i = cnt; i <= n; i++)
        ans = (ans + cnt * c(n - cnt,n - i) % mod * fac[n - i] % mod * fac[i]) % mod;
    printf("%lld",ans);
    return 0;
} 