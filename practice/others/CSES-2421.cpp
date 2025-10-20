#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
char s[5005];
int cnt[26],fac[5005],inv[5005];
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1),init();
    for (int i = 1; i <= n; i++)
        cnt[s[i] - 'a']++;
    vector<vector<int>> dp(30,vector<int>(n + 5));
    dp[0][0] = 1;
    for (int i = 0,sum = 0; i < 26; sum += cnt[i++])
    {
        if (!cnt[i])
        {
            dp[i + 1] = dp[i];
            continue;
        }
        for (int j = 0; j <= sum; j++)
            for (int k = 1; k <= cnt[i]; k++)
                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * c(j + k,k) % mod * c(cnt[i] - 1,k - 1)) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + (i & 1 ? mod - 1 : 1) * dp[26][n - i]) % mod;
    printf("%lld",ans);
    return 0;
}