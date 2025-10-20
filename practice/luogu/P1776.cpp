#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int n,m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<pii> a;
    for (int i = 1,u,v,w; i <= n; i++)
    {
        cin >> u >> v >> w;
        for (int j = 1; j <= w; j <<= 1)
        {
            a.push_back({u * j ,v * j});
            w -= j;
        }
        if (w)
            a.push_back({u * w,v * w});
    }
    vector<int>dp(m + 5);
    for (auto &[v,w] : a)
        for (int i = m; i >= w; i--)
            dp[i] = max(dp[i],dp[i - w] + v);
    cout << dp[m];
    return 0;
}