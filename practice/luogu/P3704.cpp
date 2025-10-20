#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int idx,n,m;
bool vis[maxn];
int mu[maxn],pr[maxn];
int a[maxn],inv[maxn],f[maxn];
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
void init(int n = 1e6)
{
    a[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i - 2]) % mod;
        inv[i] = binpow(a[i],mod - 2);
    }
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            mu[i] = -1;
            pr[++idx] = i;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mu[i * pr[j]] = -mu[i];
        }
    }
    fill(f + 1,f + n + 1,1);
    for (int d = 1; d <= n; d++)
    {
        for (int i = d; i <= n; i += d)
        {
            if (mu[i / d] == 1)
                f[i] = f[i] * a[d] % mod;
            else if (mu[i / d] == -1)
                f[i] = f[i] * inv[d] % mod;
        }
    }
    f[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        inv[i] = binpow(f[i],mod - 2);
        f[i] = f[i] * f[i - 1] % mod;
        inv[i] = inv[i] * inv[i - 1] % mod;
    }
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    int up = min(n,m),ans = 1;
    for (int l = 1,r; l <= up; l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        ans = ans * binpow(f[r] * inv[l - 1] % mod,(n / l) * (m / l)) % mod;
    }
    printf("%lld\n",ans);
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}