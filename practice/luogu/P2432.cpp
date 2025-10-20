#include<bits/extc++.h>
using namespace std;
int m,n;
int dp[305];
char s[305],dic[605][30];
signed main()
{
    scanf("%d%d",&m,&n);
    scanf("%s",s + 1);
    for (int i = 1; i <= m; i++)
        scanf("%s",dic[i] + 1);
    iota(dp + 1,dp + n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int p1 = i,p2 = strlen(dic[j] + 1),cnt = 0;
            while (p1 && p2)
            {
                if (s[p1--] == dic[j][p2])
                    p2--;
                else
                    cnt++;
            }
            if (!p2)
                dp[i] = min(dp[i],dp[p1] + cnt);
        }
    }
    cout << dp[n];
    return 0;
}