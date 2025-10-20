#include<bits/extc++.h>
using namespace std;
using ld = long double;
int n,t,m,k;
ld dp[35][35];
// dp[i][j] 表示还有 i 轮，还要 j 次，能赢的概率。
void dfs(int pos,int lst,int sum,ld tmp,int i,int j)
{
    if (sum == m || pos == n)
    {
        dp[i][j] = max(dp[i][j],(tmp + dp[i - 1][j] * (n - pos)) / n);
        return;
    }
    for (int x = lst; x <= m - sum; x++)
        dfs(pos + 1,x,sum + x,tmp + dp[i - 1][max(0,j - x)],i,j);
}
signed main()
{
    cin >> n >> t >> m >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++)
        for (int j = 0; j <= k; j++)
            dfs(0,1,0,0,i,j);
    cout << fixed << setprecision(8) << dp[t][k];
    return 0;
}