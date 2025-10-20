#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n;
int a[55],fac[55],inv[55];
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
void init(int n = 50)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int calc(int i,int j)
{return i > j ? 0 : fac[j] * fac[n - i - 1] % mod * inv[j - i] % mod * inv[n - 1] % mod;}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
    {
        int l = i - 1,r = i + 1;
        while (l >= 1 && a[l] < a[i])
            l--;
        while (r <= n && a[r] < a[i])
            r++;
        if (l < 1 && r > n)
        {
            printf("%lld ",n - 1);
            continue;
        }
        int ans = 0,sum = 0;
        for (int j = 1; j < n; j++)
        {
            int tmp = 0;
            if (l >= 1)
                tmp = (tmp + calc(i - l,j)) % mod;
            if (r <= n)
                tmp = (tmp + calc(r - i,j)) % mod;
            if (l >= 1 && r <= n)
                tmp = (tmp - calc(r - l,j) + mod) % mod;
            ans = (ans + (j - 1) * (tmp - sum + mod)) % mod;
            sum = tmp;
        }
        printf("%lld ",ans);
    }
    return 0;
}