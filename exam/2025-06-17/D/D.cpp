#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n,x,cnt;
int dp[maxn],sum[maxn];
int a[maxn],l[maxn],r[maxn];
signed main()
{
    scanf("%lld%lld",&n,&x);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1,cnt = 0;
        int tmp = 0;
        for (int j = 60; ~j; j--)
        {
            bool u = (a[i] >> j) & 1,v = (x >> j) & 1;
            if (!u && v)
                tmp |= 1LL << j;// 只能是 1
            else if (u && !v)
            {
                cnt++;
                l[cnt] = tmp;// 可以是 0
                r[cnt] = tmp + (1LL << j) - 1;
                tmp |= 1LL << j;// 钦定是 1
            }
            else if (!u && !v)
            {
                cnt++;
                l[cnt] = tmp + (1LL << j);// 可以是 1
                r[cnt] = tmp + (1LL << j) + (1LL << j) - 1;
                // 钦定是 0
            }
            // 只能是 0
        }
        cnt++;
        l[cnt] = r[cnt] = a[i] ^ x;
        for (int j = 1; j <= cnt; j++)
        {
            if (l[j] > a[i - 1] || r[j] < a[1])
                continue;
            int lb = lower_bound(a + 1,a + i,l[j]) - a;
            int rb = upper_bound(a + 1,a + i,r[j]) - a - 1;
            dp[i] = ((dp[i] + sum[rb] - sum[lb - 1]) % mod + mod) % mod;
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    printf("%lld",sum[n]);
    return 0;
}