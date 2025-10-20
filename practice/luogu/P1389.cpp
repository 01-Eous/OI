#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
int v[155],a[155];
int up[155][155],dn[155][155];
int dp[155][155],ans[155][155];
int calc(int l,int mid,int r)
{
    int len = (a[mid] << 1) - a[l] - a[r] + 1;
    if (a[mid] < a[l] || a[mid] < a[r] || len > n)
        return -inf;
    return up[l][mid] + dn[mid][r] + v[len];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp,~0x3f,sizeof(dp));
    memset(up,~0x3f,sizeof(up));
    memset(dn,~0x3f,sizeof(dn));
    for (int i = 1; i <= n; i++)
        dp[i][i - 1] = up[i][i] = dn[i][i] = 0;
    for (int len = 0; len <= n; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
        {
            for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j]);
            for (int k = i; k <= j; k++)
                dp[i][j] = max(dp[i][j],calc(i,k,j));
            if (a[i - 1] + 1 == a[j + 1])
                for (int l = 1; l < i; l++)
                    for (int r = j + 1; r <= n; r++)
                        up[l][r] = max(up[l][r],up[l][i - 1] + up[j + 1][r] + dp[i][j]);
            if (a[i - 1] - 1 == a[j + 1])
                for (int l = 1; l < i; l++)
                    for (int r = j + 1; r <= n; r++)
                        dn[l][r] = max(dn[l][r],dn[l][i - 1] + dn[j + 1][r] + dp[i][j]);
        }
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
        {
            ans[i][j] = max(0LL,dp[i][j]);
            for (int k = i; k < j; k++)
                ans[i][j] = max(ans[i][j],ans[i][k] + ans[k + 1][j]);
        }
    }
    cout << ans[1][n];
    return 0;
}