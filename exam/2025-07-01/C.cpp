// CF1610G
#include<bits/extc++.h>
const int maxn = 1e6 + 5;
int n,top;
char s[maxn];
unsigned pw[maxn],hsh[maxn][25];
int to[maxn],p[maxn][25],dp[maxn],st[maxn];
signed main()
{
    scanf("%s",s);
    n = strlen(s);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * 97;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st[++top] = i;
        else if (top)
            to[st[top--]] = i + 1;
    }
    p[n][0] = dp[n] = n;
    for (int i = n - 1; ~i; i--)
    {
        p[i][0] = dp[i + 1];
        hsh[i][0] = s[i];
        dp[i] = i;
        for (int j = 1; j <= 20; j++)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
            hsh[i][j] = hsh[i][j - 1] + hsh[p[i][j - 1]][j - 1] * pw[1 << (j - 1)];
        }
        if (to[i])
        {
            int x = i,y = dp[to[i]];
            for (int j = 20; j >= 0; j--)
                if (hsh[x][j] == hsh[y][j])
                    x = p[x][j],y = p[y][j];
            if (y == n || s[x] > s[y])
                dp[i] = dp[to[i]];
        }
    }
    int it = dp[0];
    while (it < n)
    {
        putchar(s[it]);
        it = p[it][0];
    }
    return 0;
}