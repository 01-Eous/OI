#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 2.5e7 + 5;
int n,mod;
int stl[5005][5005];
int fac[5005],inv[5005];
int binpow(int x,int y,int mod)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = (ll)res * x % mod;
        x = (ll)x * x % mod;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = (ll)fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2,mod);
    for (int i = n; i > 0; i--)
        inv[i - 1] = (ll)inv[i] * i % mod;
    stl[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n + 1; j++)
            stl[i][j] = (stl[i - 1][j - 1] + (ll)stl[i - 1][j] * j) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    scanf("%d%d",&n,&mod),init();
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int sum = 0,tmp = binpow(2,n - i,mod);
        for (int k = 0,p = 1; k <= i; k++,p = (ll)p * tmp % mod)
            sum = (sum + (ll)p * stl[i + 1][k + 1]) % mod;
        sum = (ll)sum * c(n,i) % mod * binpow(2,binpow(2,n - i,mod - 1),mod) % mod;
        ans = (ans + (i & 1 ? -1LL: 1LL) * sum + mod) % mod;
    }
    printf("%d",ans);
    return 0;
}