#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e6 + 5;
int n,idx;
int mod,inv2,inv6;
bool vis[maxn];
int pr[maxn],phi[maxn];
unordered_map<int,int> mem;
int sq(int x){return x * x % mod;}
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
void init(int n = 5e6)
{
    vis[1] = 1,phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
    for (int i = 1; i <= n; i++)
        phi[i] = (phi[i - 1] + phi[i] * sq(i) % mod) % mod;
}
int sum2(int x){return x %= mod,x * (x + 1) % mod * inv2 % mod;}
int sum3(int x){return x %= mod,x * (x + 1) % mod * (x << 1 | 1) % mod * inv6 % mod;}
int du(int x)
{
    if (x <= 5e6)
        return phi[x];
    else if (mem.find(x) != mem.end())
        return mem[x];
    int res = sq(sum2(x));
    for (int l = 2,r; l <= x; l = r + 1)
    {
        r = x / (x / l);
        int tmp = (sum3(r) - sum3(l - 1) + mod) % mod;
        res = (res - du(x / l) * tmp % mod + mod) % mod;
    }
    return mem[x] = res;
}
signed main()
{
    scanf("%lld%lld",&mod,&n);
    inv2 = binpow(2,mod - 2);
    inv6 = binpow(6,mod - 2);
    init();
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        int tmp = (du(r) - du(l - 1) + mod) % mod;
        ans = (ans + sq(sum2(n / l)) * tmp) % mod;
    }
    printf("%lld",ans);
    return 0;
}