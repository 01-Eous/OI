#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,m;
char s[5005];
int dp[2][5005];
signed main()
{
    scanf("%lld%s",&n,s + 1);
    m = strlen(s + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = i & 1,lst = !cur;
        dp[cur][0] = (dp[lst][0] + (dp[lst][1] << 1) % mod) % mod;
        for (int j = 1; j <= i; j++)
            dp[cur][j] = (dp[lst][j - 1] + (dp[lst][j + 1] << 1) % mod) % mod;
    }
    printf("%lld",dp[n & 1][m]);
    return 0;
}