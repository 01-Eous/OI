#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int m;
int dp[maxn];
void init(int n = 5e5)
{
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j)
                continue;
            int x = j,y = i / j;
            if (x > 2)
                dp[i] = min(dp[i],dp[x - 2] + dp[y]);
            if (y > 2)
                dp[i] = min(dp[i],dp[y - 2] + dp[x]);
        }
    }
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld",&m);
        if (m & 1)
            printf("%lld\n",dp[m]);
        else
            puts("-1");
    }
    return 0;
}