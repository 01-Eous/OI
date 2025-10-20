#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 998244353;
int n;
int stk[maxn],top;
int a[maxn],dp[maxn][2],sum[maxn][2];
void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] >= a[i])
            top--;
        if (top)
        {
            int j = stk[top];
            dp[i][0] = (dp[j][0] + (sum[i - 1][1] - sum[j - 1][1] + mod) % mod * a[i]) % mod;
            dp[i][1] = (dp[j][1] + (sum[i - 1][0] - sum[j - 1][0] + mod) % mod * a[i]) % mod;
        }
        else
        {
            dp[i][0] = sum[i - 1][1] * a[i] % mod;
            dp[i][1] = sum[i - 1][0] * a[i] % mod;
        }
        sum[i][0] = (sum[i - 1][0] + dp[i][0]) % mod;
        sum[i][1] = (sum[i - 1][1] + dp[i][1]) % mod;
        stk[++top] = i;
    }
    int ans;
    if (n & 1)
        ans = (dp[n][1] - dp[n][0] + mod) % mod;
    else
        ans = (dp[n][0] - dp[n][1] + mod) % mod;
    printf("%lld",ans);
    return 0;
}