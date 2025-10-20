#include<bits/extc++.h>
using namespace std;
int n;
int cost[4005][4005];
bitset<4005> dp[4005];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
bool chk(int mid)
{
    for (int i = 1; i <= n; i++)
        dp[i].reset();
    for (int i = 2; i <= n; i++)
        dp[i][i - 1] = 1;
    for (int l = n - 1; l >= 1; l--)
    {
        for (int r = l + 1; r <= n; r += 2)
        {
            if (cost[l][r] <= mid)
                dp[l][r] = dp[l][r] | dp[l + 1][r - 1];
            if (dp[l][r])
                dp[l] |= dp[r + 1];
        }
    }
    return dp[1][n];
}
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j += 2)
            cost[i][j] = read();
    int l = 1,r = (n * n) >> 2,mid,ans;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);
    return 0;
}