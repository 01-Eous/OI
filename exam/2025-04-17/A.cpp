#include<bits/extc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx","avx2")
using namespace std;
using ll = long long;
const int mod = 998244353;
char buf[1 << 23],*p1 = buf,*p2 = buf;
int n,m;
int a[105],b[105],c[305][305];
int dp[2][305][305],sum[2][305][305];
__int128 tmp;
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void init(int m = 300)
{
    c[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= m; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
}
signed main()
{
    init();
    n = read(),m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    dp[0][0][0] = sum[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int u = i & 1,v = u ^ 1;
        for (int j = 0; j <= m; j++)
        {
            for (int k = a[i]; k <= b[i]; k++)
            {
                tmp = 0;
                #pragma GCC unroll 8
                for (int l = min(k,j); ~l; l--)
                    tmp += (ll)sum[v][j - l][k - l] * c[j][l];
                dp[u][j][k] = tmp % mod;
            }
            for (int k = b[i + 1]; ~k; k--)
            {
                dp[v][j][k] = tmp = 0;
                #pragma GCC unroll 8
                for (int l = b[i]; l >= k; l--)
                    tmp += (ll)dp[u][j][l] * c[l][k];
                sum[u][j][k] = tmp % mod;
            }
        }
    }
    int ans = 0;
    for (int i = a[n]; i <= b[n]; i++)
        ans = (ans + dp[n & 1][m][i]) % mod;
    printf("%d",ans);
    return 0;
}