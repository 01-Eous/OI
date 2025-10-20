#include<bits/extc++.h>
using namespace std;
const int maxn = 2005;
int t,mxp,w;
int ap[maxn],bp[maxn],as[maxn],bs[maxn];
int dp[maxn][2005];
deque<int>q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> mxp >> w;
    for (int i = 1; i <= t; i++)
        cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
    memset(dp,~0x3f,sizeof dp);
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= as[i]; j++)
            dp[i][j] = -j * ap[i];
        for (int j = 0; j <= mxp; j++)
            dp[i][j] = max(dp[i][j],dp[i - 1][j]);
        if (i <= w)
            continue;
        q.clear();
        for (int j = 0; j <= mxp; j++)
        {
            while (!q.empty() && q.front() < j - as[i])
                q.pop_front();
            while (!q.empty() && dp[i - w - 1][q.back()] + q.back() * ap[i] <= dp[i - w - 1][j] + j * ap[i])
                q.pop_back();
            if (!q.empty())
                dp[i][j] = max(dp[i][j],dp[i - w - 1][q.front()] + q.front() * ap[i] - j * ap[i]);
            q.push_back(j);
        }
        q.clear();
        for (int j = mxp; j >= 0; j--)
        {
            while (!q.empty() && q.front() > j + bs[i])
                q.pop_front();
            while (!q.empty() && dp[i - w - 1][q.back()] + q.back() * bp[i] <= dp[i - w - 1][j] + j * bp[i])
                q.pop_back();
            if (!q.empty())
                dp[i][j] = max(dp[i][j],dp[i - w - 1][q.front()] + q.front() * bp[i] - j * bp[i]);
            q.push_back(j);
        }
    }
    int ans = 0;
    for (int i = 0; i <= mxp; i++)
        ans = max(ans,dp[t][i]);
    cout << ans;
    return 0;
}