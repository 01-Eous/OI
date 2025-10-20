#include<bits/extc++.h>
using namespace std;
int n,m,d,s;
int a[5005],pre[5005];
int min1[5005][5005],dp[2][5005];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x *= f;
}
signed main()
{
    n = read(),m = read();
    memset(dp,~0x3f,sizeof(dp));
    memset(min1,0x3f,sizeof(min1));
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            min1[i][j] = min(min1[i][j - 1],a[j]);
    dp[0][1] = n;
    for (int i = 1; i <= min(n,m); i++)
    {
        d = read(),s = read();
        int cur = i & 1,lst = !cur;
        memset(dp[cur],~0x3f,sizeof(dp[cur]));
        for (int j = 1; j <= n; j++)
            pre[j] = max(pre[j - 1],dp[lst][j]);
        for (int j = d + 1; j <= n; j++)
            if (min1[j - d][j - 1] >= s)
                dp[cur][j] = pre[j - d];
        int pos = 1,max1 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dp[lst][j] - j + 1 >= d)
            {
                while (pos + d - 1 <= dp[lst][j])
                {
                    max1 = max(max1,min1[pos][pos + d - 1] >= s ? pos : 0);
                    pos++;
                }
                dp[cur][j] = max(dp[cur][j],max1 - 1);
            }
        }
        bool fl = 1;
        for (int j = 1; j <= n; j++)
            fl &= j - dp[cur][j] > 1;
        if (fl)
            return printf("%d",i - 1),0;
    }
    printf("%d",min(n,m));
    return 0;
}
