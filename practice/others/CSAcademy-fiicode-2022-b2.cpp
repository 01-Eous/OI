#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 1e7 + 5;
int n,m;
char s[maxn];
int dp[maxn];
void solve()
{
    scanf("%lld%lld%s",&n,&m,s + 1);
    int x = n / m,y = (n + m - 1) / m;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        if (i >= x && s[i - x + 1] != '0')
            dp[i] = (dp[i] + dp[i - x]) % mod;
        if (x != y && i >= y && s[i - y + 1] != '0')
            dp[i] = (dp[i] + dp[i - y]) % mod;
    }
    printf("%lld\n",dp[n]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}