#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n,m,idx;
bool vis[maxn];
int pr[maxn],sum[maxn],mu[maxn];
void init(int n = 1e7)
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mu[i * pr[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= idx; i++)
        for (int j = 1; j * pr[i] <= n; j++)
            sum[j * pr[i]] += mu[j];
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    if (n > m)
        swap(n,m);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        ans += (n / l) * (m / l) * (sum[r] - sum[l - 1]);
    }
    printf("%lld\n",ans);
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