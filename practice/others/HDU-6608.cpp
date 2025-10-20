#include<bits/extc++.h>
#define int long long
using namespace std;
using i128 = __int128_t;
const int maxn = 1e7 + 5;
int p,cnt;
int pr[maxn];
bool ipr[maxn];
void init(int n = 1e7)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++cnt] = i;
        for (int j = 1; j <= cnt && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
bool isprime(int x)
{
    if (x <= 1e7)
        return !ipr[x];
    for (int i = 1; i <= cnt && pr[i] * pr[i] <= x; i++)
        if (x % pr[i] == 0)
            return 0;
    return 1;
}
i128 binpow(i128 x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}
void solve()
{
    scanf("%lld",&p);
    int q = p - 1;
    i128 tmp = 1;
    while (!isprime(q))
        q--;
    for (int i = q + 1; i < p - 1; i++)
        tmp = tmp * i % p;
    printf("%lld",(int)binpow(tmp,p - 2));
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