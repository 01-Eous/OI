#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,max1,p1,max2,p2;
int a[maxn],b[maxn],pw[maxn];
void solve()
{
    scanf("%lld",&n);
    for (int i = 0; i < n; i++)
        scanf("%lld",a + i);
    for (int i = 0; i < n; i++)
        scanf("%lld",b + i);
    max1 = max2 = p1 = p2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max1)
        {
            max1 = a[i];
            p1 = i;
        }
        if (b[i] > max2)
        {
            max2 = b[i];
            p2 = i;
        }
        if (max1 > max2)
            printf("%lld ",(pw[a[p1]] + pw[b[i - p1]]) % mod);
        else if (max1 < max2)
            printf("%lld ",(pw[a[i - p2]] + pw[b[p2]]) % mod);
        else
        {
            if (b[i - p1] > a[i - p2])
                printf("%lld ",(pw[a[p1]] + pw[b[i - p1]]) % mod);
            else
                printf("%lld ",(pw[a[i - p2]] + pw[b[p2]]) % mod);
        }
    }
    putchar('\n');
}
signed main()
{
    pw[0] = 1;
    for (int i = 1; i < 1e5; i++)
        pw[i] = (pw[i - 1] << 1) % mod;
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}