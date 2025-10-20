#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define re register
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e7 + 5;
int n,p;
bool ipr[maxn];
int phi[maxn],pr[maxn],cnt;
inline void prime(int up)
{
    for (re int i = 2; i <= up; i++)
    {
        if (!ipr[i])
        {
            pr[++cnt] = i;
            phi[i] = i - 1;
        }
        for (re int j = 1; j <= cnt; j++)
        {
            if (i * pr[j] > up)
                break;
            ipr[i * pr[j]] = 1;
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
        }
    }
}
inline int binpow(int x,int y)
{
    re int ret = 1;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    prime(n);
    re int ans = p;
    for (re int i = 2; i <= n; i++)
        ans = (ans + phi[i] * (binpow(i,p) - 1 + mod) % mod * inv(i - 1) % mod) % mod;
    cout << ans;
    return 0;
}