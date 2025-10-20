#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],dp[maxn][2],pre[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp,~0x3f,sizeof dp);
    memset(pre,~0x3f,sizeof pre);
    dp[0][1] = 0,dp[1][1] = a[1];
    pre[0] = 0,pre[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = pre[i - 2];
        dp[i][1] = max(dp[i - 1][0],dp[i - 1][1]) + a[i];
        pre[i] = max(dp[i][1],pre[i - 2]);
    }
    cout << max(dp[n][0],dp[n][1]);
    return 0;
}