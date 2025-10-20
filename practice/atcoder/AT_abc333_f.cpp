#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 998244353;
const int inv2 = 499122177;
int n;
int pw2[3005],dp[3005][3005];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld",&n);
    pw2[0] = 1;
    for (int i = 1; i <= n; i++)
        pw2[i] = (pw2[i - 1] << 1) % mod;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
            sum = (sum + pw2[j] * dp[i - 1][j]) % mod;
        dp[i][i] = sum * inv(pw2[i] - 1) % mod;
        dp[i][1] = dp[i][i] * inv2 % mod;
        for (int j = 2; j < i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod * inv2 % mod;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ",dp[n][i]);
    return 0;
}