#include<bits/extc++.h>
using namespace std;
const int maxn = 3e6 + 5;
int n,m;
int dp[maxn];
vector<int> g[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,x,y; i <= n; i++)
    {
        cin >> x >> y;
        m = max(m,y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = dp[i - 1];
        for (auto j : g[i])
            dp[i] = max(dp[i],dp[j - 1] + i - j + 1);
    }
    cout << dp[m];
    return 0;
}