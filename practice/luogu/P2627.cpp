#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
int sum[maxn],dp[maxn][2];
deque<int>q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
        while (!q.empty() && i - q.front() > k)
            q.pop_front();
        int j = q.front();
        dp[i][1] = dp[j][0] - sum[j] + sum[i];
        while (!q.empty() && dp[q.back()][0] - sum[q.back()] < dp[i][0] - sum[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << max(dp[n][0],dp[n][1]);
    return 0;
}