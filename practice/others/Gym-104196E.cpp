#include <bits/extc++.h>
using namespace std;
int n,m,p;
__int128 dp[35][35];
__int128 dfs(int x,int pos)
{
    if (pos == p)
        return !x;
    if (!x)
        return 0;
    if (~dp[x][pos])
        return dp[x][pos];
    return dp[x][pos] = 2 * x * dfs(x - 1,pos + 1) + (m - pos - 2 * x) * dfs(x,pos + 1);
}
void write(__int128 x)
{
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
signed main()
{
    cin >> m >> n >> p;
    memset(dp,-1,sizeof dp);
    __int128 ans = dfs(n,0);
    __int128 div = 1;
    for (int i = m - p + 1; i <= m; i++)
    {
        div *= i;
        __int128 tmp = __gcd(ans,div);
        ans /= tmp,div /= tmp;
    }
    __int128 tmp = __gcd(ans,div);
    ans /= tmp,div /= tmp;
    write(ans),putchar('/'),write(div);
    return 0;
}