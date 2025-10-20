#include<bits/extc++.h>
#define int long long
using namespace std;
int mod;
int a[20];
int dp[20][200];
int dfs(int pos,bool lim,int sum)
{
    if (!pos)
        return sum;
    if (!lim && ~dp[pos][sum])
        return dp[pos][sum];
    int up = lim ? a[pos] : 9,ret = 0;
    for (int i = 0; i <= up; i++)
        ret = (ret + dfs(pos - 1,lim && i == up,sum + i)) % mod;
    if (!lim)
        dp[pos][sum] = ret;
    return ret;
}
int getans(int x)
{
    int idx = 0;
    while(x)
    {
        a[++idx] = x % 10;
        x /= 10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(idx,1,0);
}
signed main()
{
    cin >> mod;
    int x = mod - getans(999999999999999999);
    cout << x << ' ' << 999999999999999999 + x;
    return 0;
}