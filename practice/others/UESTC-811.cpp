#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e6 + 5;
const int mod = 1e9 + 7;
int n,k,idx;
bool vis[maxn];
int inv[8],c[8][8];
int pr[maxn],phi[maxn];
unordered_map<int,int> mem;
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
    for (int i = 1; i <= 6; i++)
        inv[i] = binpow(i,mod - 2);
    for (int i = 0; i <= 6; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    vis[1] = 1,phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = (i - 1) % mod;
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
int sum(int n,int k)
{
    int res = binpow((n + 1) % mod,k + 1);
    for (int j = 0; j < k; j++)
        res = (res - c[k + 1][j] * sum(n,j) % mod + mod) % mod;
    return res * inv[k + 1] % mod;
}
int du(int n)
{
    if (n <= 5e6)
        return phi[n];
    if (mem.find(n) != mem.end())
        return mem[n];
    int res = n % mod * ((n + 1) % mod) % mod * inv[2] % mod;
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res = (res - (r - l + 1) * du(n / l) % mod + mod) % mod;
    }
    return mem[n] = res;
}
signed main()
{
    init(5e6);
    scanf("%lld%lld",&n,&k);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + (sum(r,k) - sum(l - 1,k) + mod) % mod * du(n / l)) % mod;
    }
    ans = ((ans << 1) % mod - sum(n,k) + mod) % mod;
    printf("%lld\n",ans);
    return 0;
}