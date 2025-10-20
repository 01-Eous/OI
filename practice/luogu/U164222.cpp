#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n,m,idx;
bool vis[maxn];
int pr[maxn],low[maxn],pw[maxn],sum[maxn];
void init(int n = 1e7)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            low[i] = i;
            pw[i] = sum[i] = 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                pw[i * pr[j]] = pw[i] + 1;
                low[i * pr[j]] = low[i] * pr[j];
                if (i == low[i])
                    sum[i * pr[j]] = 1;
                else
                    sum[i * pr[j]] = pw[i / low[i]] == pw[i * pr[j]] ? -sum[i / low[i]] : 0;
                break;
            }
            pw[i * pr[j]] = 1;
            low[i * pr[j]] = pr[j];
            sum[i * pr[j]] = pw[i] == 1 ? -sum[i] : 0;
        }
    }
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
        ans += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
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