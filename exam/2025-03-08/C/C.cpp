#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,k,mod;
int a[maxn];
int count()
{
    int ret = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            ret += a[j] > a[i];
    return ret;
}
signed main()
{
    scanf("%lld%lld%lld",&n,&k,&mod);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans1,ans2,ans3,cnt1,cnt2;
    ans1 = ans2 = ans3 = cnt1 = cnt2 = 0;
    do
    {
        ans1 = (ans1 + count()) % mod;
        cnt1++;
    } while (next_permutation(a + 1,a + n + 1));
    iota(a + 1,a + n + 1,1);
    do
    {
        ans2 = (ans2 + count()) % mod;
        cnt2 ++;
    } while (next_permutation(a + 1,a + n + 1));
    iota(a + 1,a + n + 1,1);
    int m = (k - cnt1) % cnt2;
    for (int i = 1; i <= m; i++)
    {
        ans3 = (ans3 + count()) % mod;
        next_permutation(a + 1,a + n + 1);
    }
    cout << (ans1 + ans3 + (ans2 * ((k - cnt1) / cnt2)) % mod) % mod;
    return 0;
}