#include<bits/extc++.h>
#define int long long
#define add(x,y) (x = (x + y + mod) % mod)
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
bool st;
int n,m,len;
int dp[maxn],f[maxn],g[2][maxn];
bool ed;
void init(int n = 3e5)
{
    g[0][0] = f[0] = 1;
    len = sqrt(n);
    for (int i = 1; i <= n / len; i++)
    {
        int x = i & 1,y = x ^ 1;
        for (int j = 0; i * len + j <= n; j++)
        {
            g[x][j] = 0;
            if (j)
                add(g[x][j],g[y][j - 1]);
            if (j >= i)
                add(g[x][j],g[x][j - i]);
            add(f[i * len + j],g[x][j]);
        }
    }
    for (int i = 1; i <= len; i++)
        for (int j = i; j <= n; j++)
            add(f[j],f[j - i]);
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    memset(dp,0,sizeof(int) * (m + 5));
    dp[0] = 1;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        for (int j = m; j >= x; j--)
            add(dp[j],-dp[j - x]);
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        add(ans,dp[i] * f[m - i] % mod);
    printf("%lld\n",ans);
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}