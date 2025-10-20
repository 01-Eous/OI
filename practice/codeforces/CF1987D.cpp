#include<bits/extc++.h>
using namespace std;
const int maxn = 5005;
int n,m;
int a[maxn],cnt[maxn],dp[maxn][maxn];
void solve()
{
    cin >> n;
    fill(cnt + 1,cnt + n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1,a + n + 1);
    m = unique(a + 1,a + n + 1) - a - 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= cnt[a[i]] && i > dp[i - 1][j - cnt[a[i]]] + j)
                dp[i][j] = max(dp[i][j],dp[i - 1][j - cnt[a[i]]] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans,dp[m][i]);
    cout << m - ans << '\n';
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