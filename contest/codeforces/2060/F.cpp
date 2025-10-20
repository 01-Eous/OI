#include<bits/extc++.h>
#define inv(x) binpow(x,mod - 2)
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,k,m;
vector<int>fact[maxn];
inline int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
inline void init(int up = 1e5)
{
    for (int i = 2; i <= up; i++)
        for (int j = i; j <= up; j += i)
            fact[j].push_back(i);
}
inline int c(int n,int m)
{
    int ret = 1;
    for (int i = 1,j = n; i <= m; i++,j--)
        ret = ret * j % mod * inv(i) % mod;
    return ret;
}
void solve()
{
    cin >> k >> n;
    m = __lg(k) + 1;
    vector<vector<int>>dp(k + 5,vector<int>(m + 5,0));
    for (int i = 2; i <= k; i++)
    {
        dp[i][1] = 1;
        for (int j = 2; j <= m; j++)
            for (auto x : fact[i])
                dp[i][j] = (dp[i][j] + dp[i / x][j - 1]) % mod;
    }
    cout << n << " ";
    for (int i = 2; i <= k; i++)
    {
        int ans = 0;
        for (int j = 1; j <= min(n,m); j++)
            ans = (ans + c(n + 1,j + 1) * dp[i][j] % mod) % mod;
        cout << ans << " ";
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}