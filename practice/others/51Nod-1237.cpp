#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e6 + 5;
const int mod = 1e9 + 7;
const int inv6 = 166666668,inv2 = 5e8 + 4;
int n,idx;
bool vis[maxn];
int pr[maxn],phi[maxn];
unordered_map<int,int> mem;
int sq(int x){return x %= mod,x * x % mod;}
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
                phi[i * pr[j]] = phi[i] * pr[j] % mod;
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]] % mod;
        }
    }
    for (int i = 1; i <= n; i++)
        phi[i] = (phi[i - 1] + phi[i]) % mod;
}
int du(int n)
{
    if (n <= 5e6)
        return phi[n];
    if (mem.find(n) != mem.end())
        return mem[n];
    int res = (n % mod) * ((n + 1) % mod) % mod * inv2 % mod;
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res = (res - (r - l + 1) % mod * du(n / l) % mod + mod) % mod;
    }
    return mem[n] = res;
}
signed main()
{
    init();
    scanf("%lld",&n);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        int tmp = (du(r) - du(l - 1) + mod) % mod;
        ans = (ans + tmp * sq(n / l)) % mod;
    }
    printf("%lld",ans);
    return 0;
}