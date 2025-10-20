#include<bits/extc++.h>
using namespace std;
typedef double ld;
const ld eps = 1e-7;
int n,r,m,tot;
int t[60],d[60];
ld p[60],dp[60][5005];
bool chk(ld mid)
{
    for (int i = m; i >= 0; i--)
    {
        for (int j = t[i]; j < r - n + t[i]; j++)
        {
            int tim = t[i + 1] - t[i];
            dp[i][j] = p[i] * (dp[i + 1][j + tim] + tim);
            if (j + d[i] + n - t[i] < r)
                dp[i][j] += (1 - p[i]) * min(mid,dp[i + 1][j + d[i] + tim] + d[i] + tim);
            else
                dp[i][j] += (1 - p[i]) * mid;
        }
    }
    return mid > dp[0][0];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> m;
    tot = r - n - 1;
    for (int i = 1; i <= m; i++)
        cin >> t[i] >> p[i] >> d[i];
    t[m + 1] = n, p[0] = p[m + 1] = 1;
    ld l = 0,r = 3e18,mid,ans = 0;
    while (r - l >= eps)
    {
        mid = (l + r) / 2.0;
        if (chk(mid))
        {
            ans = mid;
            r = mid - eps;
        }
        else
            l = mid + eps;
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}