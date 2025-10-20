#include<bits/extc++.h>
const int maxn = 5e7 + 5;
const int mod = 1e9 + 7;
using ll = long long;
int n,m,idx;
bool vis[maxn];
int f[maxn],pr[maxn],inv[maxn];
void init()
{
    inv[1] = 1;
    for (int i = 2; i <= 30; i++)
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
}
void sieve()
{
    f[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            f[i] = n;
        }
        for (int j = 1; j <= idx && i * pr[j] <= m; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                int k = 0,x = i;
                while (x % pr[j] == 0)
                    k++,x /= pr[j];
                f[i * pr[j]] = (ll)f[i] * (n + k) % mod * inv[k + 1] % mod;
                break;
            }
            f[i * pr[j]] = (ll)f[i] * n % mod;
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    init(),sieve();
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = ((ll)ans + f[i]) % mod;
    printf("%d",ans);
    return 0;
}