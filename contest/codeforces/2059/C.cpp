#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<vector<int>>a(n + 5,vector<int>(n + 5));
    vector<int>sum(n + 5,0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (a[i][j] != 1)
                break;
            sum[i]++;
        }
    }
    sort(sum.begin() + 1,sum.begin() + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
        if (sum[i] >= ans)
            ans++;
    cout << min(n,ans) << '\n';
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