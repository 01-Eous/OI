#include<bits/extc++.h>
using namespace std;
const int py = 4e5;
int n;
int s[405],f[405];
int dp[py * 2 + 5];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> f[i];
    memset(dp,~0x3f,sizeof dp);
    dp[py] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] > 0)
            for (int j = py << 1; j >= s[i]; j--)
                dp[j] = max(dp[j],dp[j - s[i]] + f[i]);
        else
            for (int j = 0; j <= (py << 1) + s[i]; j++)
                dp[j] = max(dp[j],dp[j - s[i]] + f[i]);
    }
    int ans = 0;
    for (int i = py; i <= py << 1; i++)
        if (dp[i] >= 0)
            ans = max(ans,i - py + dp[i]);
    cout << ans;
    return 0;
}