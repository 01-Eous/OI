#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int dp[maxn];
vector<int> fac[maxn];
void init(int n = 2e5)
{
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j += i)
            fac[j].push_back(i);
}
void solve()
{
    cin >> n;
    memset(dp,0,sizeof(int) * (n + 5));
    int ans = 0,g = 0;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        for (auto j : fac[x])
            if (++dp[j] != i)
                ans = max(ans,dp[j]);
        if (__gcd(g,x) != g)
            ans = i - 1;
        g = __gcd(g,x);
        cout << ans << " \n"[i == n];
    }
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