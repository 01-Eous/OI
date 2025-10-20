#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1 << 20 | 5;
const int mod = 1e9 + 7;
int n;
int cnt[maxn];
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
    for (int i = 1,x; i <= n; i++)
        scanf("%lld",&x),cnt[x]++;
    for (int i = 0; i < 20; i++)
        for (int s = (1 << 20) - 1; ~s; s--)
            if (!((s >> i) & 1))
                cnt[s] = (cnt[s] + cnt[s | (1 << i)]) % mod;
    int ans = 0;
    for (int s = 0; s < 1 << 20; s++)
        ans = (ans + (__popcount(s) & 1 ? -1 : 1) * (binpow(2,cnt[s]) - 1) % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}