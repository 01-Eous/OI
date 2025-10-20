#include<bits/extc++.h>
using namespace std;
const int dis[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m;
void solve()
{
    cin >> n >> m;
    vector<int>cost(n * m + 5);
    vector<vector<int>>a(n + 5,vector<int>(m + 5));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            bool fl = 0;
            for (int k = 0; k < 4; k++)
            {
                int tx = i + dis[k][0];
                int ty = j + dis[k][1];
                if (a[i][j] == a[tx][ty])
                {
                    fl = 1;
                    break;
                }
            }
            cost[a[i][j]] = max(cost[a[i][j]],fl + 1);
        }
    }
    int sum = 0,_max = 0;
    for (int i = 1; i <= n * m; i++)
    {
        sum += cost[i];
        _max = max(_max,cost[i]);
    }
    cout << sum - _max << '\n';
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