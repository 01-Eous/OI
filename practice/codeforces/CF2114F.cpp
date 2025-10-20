#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int x,y,k;
int pool[maxn * 20];
int head[maxn],tail[maxn],siz[maxn];
unordered_map<int,int> dp;
void init(int n = 1e6)
{
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j += i)
            siz[j]++;
    for (int i = 2; i <= n; i++)
    {
        head[i] = head[i - 1] + siz[i - 1];
        tail[i] = head[i] - 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j += i)
            pool[++tail[j]] = i;
}
int dfs(int x)
{
    if (x == 1)
        return 0;
    if (dp.count(x))
        return dp[x];
    dp[x] = inf;
    for (int i = head[x]; i <= tail[x] && pool[i] <= k; i++)
        dp[x] = min(dp[x],dfs(x / pool[i]) + 1);
    return dp[x];
}
void solve()
{
    cin >> x >> y >> k;
    int g = __gcd(x,y);
    x /= g,y /= g,dp.clear();
    int ansx = dfs(x),ansy = dfs(y);
    if (ansx == inf || ansy == inf)
        cout << "-1\n";
    else
        cout << ansx + ansy << '\n';
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