#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
void solve()
{
    scanf("%lld",&n);
    vector<int>a(n + 5),pre(n + 5);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
        pre[i] = pre[i - 1] ^ a[i];
    }
    map<int,int>dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp[pre[i - 1]] = (dp[pre[i - 1]] * 3 % mod + (dp[pre[i]] << 1) % mod) % mod;
    int ans = 0;
    for (auto &[x,y] : dp)
        ans = (ans + y) % mod;
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