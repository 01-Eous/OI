#include<bits/extc++.h>
#define int __int128
using namespace std;
const int maxn = 1505;
int n,k;
int dp[maxn][maxn];
inline void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
void write(int x)
{
    if (x > 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
signed main()
{
    freopen("sweets.in","r",stdin);
    freopen("sweets.out","w",stdout);
    read(n),read(k);
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i][1] = 1;
    for (int i = 2; i <= k; i++)
        dp[0][i] = dp[1][i] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= k; j++)
            dp[i][j] = dp[i - 1][j - 1] + (i > j ? dp[i - j][j] : 0);
    write(dp[n][k]);
    return 0;
}