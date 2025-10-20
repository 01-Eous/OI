#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[maxn],b[maxn];
int suma[maxn],sumb[maxn],dp[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            suma[i] = (suma[i] + a[j]) % mod;
            sumb[i] = (sumb[i] + b[j]) % mod;
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        dp[i] = suma[i] * sumb[i] % mod;
        for (int j = i << 1; j <= n; j += i)
            dp[i] = (dp[i] - dp[j] + mod) % mod;
        ans = (ans + dp[i] * i) % mod;
    }
    printf("%lld",ans);
    return 0;
}