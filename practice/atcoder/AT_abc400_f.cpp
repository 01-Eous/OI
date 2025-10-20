#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
int c[805],v[405];
int dp1[805][805],dp2[805][805];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i + n] = c[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    memset(dp1,0x3f,sizeof dp1);
    memset(dp2,0x3f,sizeof dp2);
    for (int i = 1; i <= n << 1; i++)
    {
        dp1[i][i] = 1 + v[c[i]];
        dp2[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= n << 1; i++)
        {
            for (int k = i; k < j; k++)
            {
                dp1[i][j] = min(dp1[i][j],dp1[i][k] + dp1[k + 1][j]);
                dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp1[k + 1][j]);
            }
            if (c[j] == c[i])
            {
                dp2[i][j] = min(dp2[i][j],dp2[i][j - 1]);
                dp1[i][j] = min(dp1[i][j],dp2[i][j] + len + v[c[j]]);
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans,dp1[i][i + n - 1]);
    cout << ans;
    return 0;
}