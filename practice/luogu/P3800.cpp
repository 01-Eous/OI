#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,k,t;
int q[100005],head,tail;
int mp[4005][4005],dp[4005][4005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> t;
    int x,y,v;
    while (k--)
    {
        cin >> x >> y >> v;
        mp[x][y] = v;
    }
    for (int i = 1; i <= n; i++)
    {
        head = 1,tail = 0;
        for (int j = 1; j <= t; j++)
        {
            while (head <= tail && dp[i - 1][q[tail]] < dp[i - 1][j])
                tail--;
            q[++tail] = j;
        }
        for (int j = 1,p = t; j <= m; j++)
        {
            if (++p <= m)
            {
                while (head <= tail && dp[i - 1][q[tail]] < dp[i - 1][p])
                    tail--;
                q[++tail] = p;
            }
            while (head <= tail && q[head] < j - t)
                head++;
            dp[i][j] = dp[i - 1][q[head]] + mp[i][j];
        }
    }
    printf("%lld",*max_element(dp[n] + 1,dp[n] + m + 1));
    return 0;
}