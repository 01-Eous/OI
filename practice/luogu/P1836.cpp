#include<bits/extc++.h>
#define int long long
using namespace std;
int num[15],idx;
int dp[15][90];
int dfs(int pos,int lim,int sum)
{
    if (!pos)
        return sum;
    if (!lim && ~dp[pos][sum])
        return dp[pos][sum];
    int up = lim ? num[pos] : 9,res = 0;
    for (int i = 0; i <= up; i++)
        res += dfs(pos - 1,lim && i == up,sum + i);
    if (!lim)
        dp[pos][sum] = res;
    return res;
}
int solve(int x)
{
    idx = 0;
    while (x)
    {
        num[++idx] = x % 10;
        x /= 10;
    }
    memset(dp,0xff,sizeof dp);
    return dfs(idx,1,0);
}
signed main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}