#include<bits/extc++.h>
using namespace std;
int n;
int a[5005];
bool apr[5005],dp[5005][10010];
vector<pair<int,int>> g[5005];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].clear();
    }
    for (int i = 1; i <= n; i++)
        if (!a[i])
            g[i].push_back({i,1});
    for (int i = 1,tmp; i <= n; i++)
    {
        memset(apr,0,sizeof(bool) * (n + 5));
        tmp = 0;
        for (int j = i; j <= n; j++)
        {
            apr[a[j]] = 1;
            while (apr[tmp])
                tmp++;
            if (tmp > a[i] && a[j] < a[i])
            {
                g[j].push_back({i,tmp});
                break;
            }
        }
        memset(apr,0,sizeof(bool) * (n + 5));
        tmp = 0;
        for (int j = i; j >= 1; j--)
        {
            apr[a[j]] = 1;
            while (apr[tmp])
                tmp++;
            if (tmp > a[i] && a[j] < a[i])
            {
                g[i].push_back({j,tmp});
                break;
            }
        }
    }
    memset(dp[0],0,sizeof dp[0]);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        memcpy(dp[i],dp[i - 1],sizeof dp[i]);
        for (auto &[j,w] : g[i])
            for (int k = 0; k <= 1e4; k++)
                if ((k ^ w) <= 1e4)
                    dp[i][k] |= dp[j - 1][k ^ w];
    }
    for (int i = 1e4; i >= 0; i--)
        if (dp[n][i])
            return cout << i << '\n',void();
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}