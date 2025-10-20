#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int x,y;
int dp[65][65];
vector<bool> d1,d2;
void init()
{
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= 60; i++)
    {
        for (int j = 60; j >= 0; j--)
        {
            for (int k = 60; k >= 0; k--)
            {
                if (j >= i)
                    dp[j][k] = min(dp[j][k],dp[j - i][k] + (1LL << i));
                if (k >= i)
                    dp[j][k] = min(dp[j][k],dp[j][k - i] + (1LL << i));
            }
        }
    }
}
void solve()
{
    scanf("%lld%lld",&x,&y);
    d1.clear(),d2.clear();
    while (x)
    {
        d1.push_back(x & 1);
        x >>= 1;
    }
    while (y)
    {
        d2.push_back(y & 1);
        y >>= 1;
    }
    int n = d1.size(),m = d2.size();
    int ans = inf;
    for (int i = 60; i >= max(n,m); i--)
        ans = min({ans,dp[i][i],dp[i][m],dp[n][i]});
    bool fl = 1;
    for (int i = n,j = m; i >= 1 && j >= 1; i--,j--)
    {
        ans = min(ans,dp[i][j]);
        if (d1[i - 1] != d2[j - 1])
        {
            fl = 0;
            break;
        }
    }
    if (fl)
        ans = min(ans,dp[0][abs(n - m)]);
    printf("%lld\n",ans);
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}