#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,m;
int a[maxn],pw[maxn],p[maxn];
void solve()
{
    scanf("%lld%lld",&m,&n);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        pw[i] = pw[i - 1] * m % mod;
    }
    fill(p + 1,p + n + 1,0);
    for (int i = 2,j = 0; i <= n; i++)
    {
        while (j && a[j + 1] != a[i])
            j = p[j];
        if (a[j + 1] == a[i])
            j++;
        p[i] = j;
    }
    int i = n,ans = 0;
    while (i)
    {
        ans = (ans + pw[i]) % mod;
        i = p[i];
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}