#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define chkmin(x,y) (x = min(x,y))
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[3],dp1[maxn],dp2[maxn][8];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a[0] >> a[1] >> a[2] >> n;
    memset(dp1,0x3f,sizeof dp1);
    dp1[0] = 0;
    for (int i = 1; i <= n + 1e5; i++)
        for (int j = 0; j < 3; j++)
            if (i >= a[j])
                chkmin(dp1[i],dp1[i - a[j]] + 2);
    memset(dp2,0x3f,sizeof dp2);
    for (int i = 1; i <= n + 1e5; i++)
        dp2[i][0] = dp1[i];
    for (int i = n + 1e5; i >= 1; i--)
        for (int k = 0; k < 8; k++)
            for (int j = 0; j < 3; j++) 
                if (a[j] + i <= n + 1e5)
                    chkmin(dp2[i][k | (1 << j)],dp2[i + a[j]][k] + 2);
    for (int i = 1; i <= n; i++)
    {
        int ans = inf;
        for (int k = 0; k < 8; k++) 
            if (dp2[i][k] != inf)
                chkmin(ans,dp2[i][k] - __builtin_popcount(k));
        cout << (ans == inf ? -1 : ans) << ' ';
    }
    return 0;
}