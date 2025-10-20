#include<bits/extc++.h>
#define chkmax(x,y) x = max(x,y)
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
int n,m;
char s[maxn],str[maxm];
int dp[maxm],lft[maxm],rht[maxm];
void manacher()
{
    str[1] = '#';
    for (int i = 1; i <= n; i++)
    {
        str[i << 1] = s[i];
        str[i << 1 | 1] = '#';
    }
    m = strlen(str + 1);
    int r = 0,mid = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i <= r)
            dp[i] = min(r - i + 1,dp[(mid << 1) - i]);
        while (i - dp[i] >= 1 && i + dp[i] <= m && str[i - dp[i]] == str[i + dp[i]])
            dp[i]++;
        if (r < i + dp[i])
        {
            mid = i;
            r = i + dp[i] - 1;
        }
        chkmax(lft[i - dp[i] + 1],dp[i] - 1);
        chkmax(rht[i + dp[i] - 1],dp[i] - 1);
    }
    // for (int i = 1; i <= m; i++)
    //     printf("%d ",dp[i]);
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    manacher();
    for (int i = 1; i <= m; i += 2)
        chkmax(lft[i],lft[i - 2] - 2);
    for (int i = m; i >= 1; i -= 2)
        chkmax(rht[i],rht[i + 2] - 2);
    int ans = 0;
    for (int i = 1; i <= m; i += 2)
        if (lft[i] && rht[i])
            chkmax(ans,lft[i] + rht[i]);
    printf("%d",ans);
    return 0;
}