#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7,inv2 = 5e8 + 4;
int n,dp[maxn];
char s[maxn];
void solve()
{
    scanf("%lld%s",&n,s + 1);
    int ans = 0;
    for (int i = n; i > 1; i--)
        ans = (ans + (s[i] == '1')) * inv2 % mod;
    printf("%lld\n",n - 1 + ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}