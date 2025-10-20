#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 5;
int n,m,idx;
bool ipr[maxn];
int pr[maxn],mo[maxn],d[maxn],sum[maxn];
void init(int n = 5e4)
{
    mo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            mo[i] = -1;
            pr[++idx] = i;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mo[i * pr[j]] = -mo[i];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            d[j]++;
    for (int i = 1; i <= n; i++)
    {
        mo[i] += mo[i - 1];
        sum[i] = sum[i - 1] + d[i];
    }
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    int up = min(n,m),ans = 0;
    for (int l = 1,r; l <= up; l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        ans += (mo[r] - mo[l - 1]) * sum[n / l] * sum[m / l];
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