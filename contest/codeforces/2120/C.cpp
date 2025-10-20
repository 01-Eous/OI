// 不开 long long 见祖宗
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
int a[maxn];
bool vis[maxn];
void solve()
{
    scanf("%lld%lld",&n,&m);
    m -= n;
    if (m < 0)
        return (void)puts("-1");
    fill(a + 1,a + n + 1,1);
    int idx = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (m >= i)
        {
            a[idx++] += i;
            m -= i;
        }
    }
    if (m)
        return (void)puts("-1");
    fill(vis + 1,vis + n + 1,0);
    for (int i = 1; i <= idx; i++)
        vis[a[i]] = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            a[++idx] = i;
    printf("%lld\n",a[1]);
    for (int i = 2; i <= n; i++)
        printf("%lld %lld\n",a[i - 1],a[i]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}