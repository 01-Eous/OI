#include<bits/extc++.h>
#define int long long
#define lowbit(x) ((x) & (-(x)))
#define check(x,j) (j == 0 || x <= lowbit(j))
using namespace std;
const int maxn = 1005;
const int maxm = 1 << 13 | 5;
int n,sum;
int a[maxn],h[maxm];
int to[maxn][maxm];
bool dp[maxn][maxm];
char ans[maxn][maxm],out[maxn];
void init()
{
    for (int i = 1; i <= (1 << 13); i++)
    {
        if (i == lowbit(i))
            h[i] = i;
        else
            h[i] = h[i >> 1] << 1;
    }
}
void print(int i,int j)
{
    if (!i)
        return;
    out[i] = ans[i][j];
    print(i - 1,to[i][j]);
}
inline void solve()
{
    scanf("%lld",&n);
    sum = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum += a[i];
        fill(dp[i],dp[i] + sum + 1,0);
    }
    if (lowbit(sum) != sum)
    {
        puts("no");
        return;
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (!dp[i - 1][j])
                continue;
            if (check(a[i],j))
            {
                dp[i][j + a[i]] = 1;
                to[i][j + a[i]] = j;
                ans[i][j + a[i]] = 'l';
            }
            if (check(a[i],sum - j))
            {
                dp[i][j] = 1;
                to[i][j] = j;
                ans[i][j] = 'r';
            }
        }
        sum += a[i];
        for (int j = 0; j <= sum; j++)
        {
            if (!dp[i][j])
                continue;
            if (h[j] < h[sum - j])
            {
                dp[i][j + h[sum - j]] = 1;
                to[i][j + h[sum - j]] = to[i][j];
                ans[i][j + h[sum - j]] = ans[i][j];
            }
            else if (h[j] > h[sum - j])
            {
                dp[i][j - h[j]] = 1;
                to[i][j - h[j]] = to[i][j];
                ans[i][j - h[j]] = ans[i][j];
            }
            else
            {
                dp[i][j] = 0;
                dp[i][j - h[j]] = dp[i][j + h[j]] = 1;
                to[i][j - h[j]] = to[i][j + h[j]] = to[i][j];
                ans[i][j - h[j]] = ans[i][j + h[j]] = ans[i][j];
            }
        }
    }
    if (dp[n][sum])
    {
        print(n,sum);
        for (int i = 1; i <= n; i++)
            putchar(out[i]);
        putchar('\n');
    }
    else
        puts("no");
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