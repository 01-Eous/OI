#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 924844033;
int n,m,idx;
int fac[2005];
bool can[4005];
int dp[4005][2005][2];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
        for (int _ = 0; _ < 2; _++)
            for (int j = i; j <= n; j += m)
                if (idx++; i != j)
                    can[idx] = 1;
    assert(idx == n << 1);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n << 1; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            if (j && can[i])
                dp[i][j][1] = dp[i - 1][j - 1][0];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + (i & 1 ? -1 : 1) * (dp[n << 1][i][0] + dp[n << 1][i][1]) % mod * fac[n - i] % mod + mod) % mod;
    cout << ans;
    return 0;
}