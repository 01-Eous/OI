#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m;
void solve()
{
    scanf("%lld%lld",&n,&m);
    vector<vector<int>> dp(n + 5,vector<int>(m + 5,0));
    // dp[i][j] 表示已经有 i 个好子串，当前这个 1 前面有 j 个 0
    // 将序列分成 114514 段 00...001 的形式。
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k + j < m && (k + 1) * (j + 1) <= i; k++)
                dp[i][j] = (dp[i][j] + dp[i - (k + 1) * (j + 1)][k]) % mod;
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = (ans + dp[n][i]) % mod;
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