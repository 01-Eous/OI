#include<bits/extc++.h>
#define int long long
#define chkmax(x,y) (x = max(x,y))
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
char buf[1 << 21],*p1,*p2;
int n,q;
int a[maxn],dp[55][55];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
int calc(int l,int r)
{
    int n = r - l + 1;
    memset(dp,~0x3f,sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[l + i - 1];
    for (int len = 2; len <= n; len++)
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
            for (int k = i; k < j; k++)
                chkmax(dp[i][j],dp[i][k] + (dp[k + 1][j] << 1));
    return dp[1][n];
}
signed main()
{
    n = read(),q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    while (q--)
    {
        int l = read(),r = read();
        printf("%lld\n",(calc(l,r) + mod) % mod);
    }
    return 0;
}