#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,m,idx;
bool ipr[maxn];
int pr[maxn],mo[maxn],sum[maxn];
void init(int n = 1e6)
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
            sum[j] += mo[i] * mo[j / i];
}
int calc(int n,int x)
{
    int res = 0;
    for (int i = x; i <= n; i += x)
        res += mo[i];
    return res;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    int ans = 0;
    for (int i = 1; i <= min(n,m); i++)
        ans += calc(n,i) * calc(m,i) * sum[i];
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