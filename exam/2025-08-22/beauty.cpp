#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,V;
int pw[5005][5005];
int fac[5005],inv[5005];
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
void init(int n = 5000)
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n; i > 0; i--)
        inv[i - 1] = inv[i] * i % mod;
    for (int i = 1; i <= n; i++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= n; j++)
            pw[i][j] = pw[i][j - 1] * i % mod;
    }
}
int c(int n,int m){return fac[n] * inv[m] % mod * inv[n - m] % mod;}
void solve()
{
    scanf("%lld%lld",&n,&V);
    int ans = 0;
    for (int v = 1; v < V; v++)
        for (int c0 = 1; c0 < n; c0++)
            ans = (ans + min(c0,n - c0) * pw[v][c0] % mod * pw[V - v][n - c0] % mod * c(n,c0)) % mod;
    printf("%lld\n",(ans << 1) % mod);
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