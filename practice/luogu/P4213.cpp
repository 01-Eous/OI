#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n,idx;
bool vis[maxn];
int pr[maxn],mu[maxn],phi[maxn];
__gnu_pbds::gp_hash_table<int,int> memm,memp;
void init(int n = 1e7)
{
    mu[1] = phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            mu[i] = -1;
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
            mu[i * pr[j]] = -mu[i];
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mu[i] += mu[i - 1];
        phi[i] += phi[i - 1];
    }
}
int getMu(int n)
{
    if (n <= 1e7)
        return mu[n];
    if (memm.find(n) != memm.end())
        return memm[n];
    int res = 1;
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res -= (r - l + 1) * getMu(n / l);
    }
    return memm[n] = res;
}
int sumPhi(int n)
{
    if (n <= 1e7)
        return phi[n];
    if (memp.find(n) != memp.end())
        return memp[n];
    int res = n * (n + 1) >> 1;
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res -= (r - l + 1) * sumPhi(n / l);
    }
    return memp[n] = res;
}
void solve()
{
    scanf("%lld",&n);
    printf("%lld %lld\n",sumPhi(n),getMu(n));
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