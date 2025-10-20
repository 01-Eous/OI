#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
int n,mod;
int dp[maxn][maxn],fac[maxn];
signed main() 
{
    cin >> n >> mod;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] * j % mod + dp[i - 1][j] * (i - j - 1) % mod) % mod;
        dp[i][1] = (dp[i][1] + fac[i]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + i * (n - i) % mod * dp[n][i] % mod) % mod;
    cout << ans;
    return 0;
}