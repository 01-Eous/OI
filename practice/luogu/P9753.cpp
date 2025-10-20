#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5;
int n;
char s[maxn];
int dp[maxn],g[maxn];
signed main()
{
    scanf("%lld%s",&n,s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i - 1;
        while (g[i] > 0 && s[i] != s[g[i]])
            g[i] = g[g[i]] - 1;
        if (g[i] <= 0)
            dp[i] = 0;
        else
            dp[i] = dp[g[i] - 1] + 1;
        ans += dp[i];
    }
    cout << ans;
    return 0;
}