#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k;
int sum[505][505];
char mp[505][505];
int calc(int x,int y)
{
    int sx = x - k + 1,sy = y - k + 1;
    int tx = x + k - 1,ty = y + k - 1;
    sx = max(1,sx),sy = max(1,sy);
    tx = min(tx,n),ty = min(ty,m);
    return sum[tx][ty] - sum[sx - 1][ty] - sum[tx][sy - 1] + sum[sx - 1][sy - 1];
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            sum[i][j] = mp[i][j] == 'g';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j];
    int ans = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '.')
                ans = min(ans,calc(i,j));
    cout << sum[n][m] - ans << '\n';
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