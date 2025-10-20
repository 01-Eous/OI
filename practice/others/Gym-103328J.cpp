#include<bits/extc++.h>
#define int long long
#define add(x,y) (x = (x + y) % mod)
using namespace std;
const int maxn = 1 << 20 | 5;
const int mod = 1000000007;
const int inv[] = {
    0,1,500000004,333333336,250000002,400000003,
    166666668,142857144,125000001,111111112,700000005,
    818181824,83333334,153846155,71428572,466666670,
    562500004,352941179,55555556,157894738,850000006
};
int n;
int g[25][25],dp[maxn][25],ans[25];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld",g[i] + j);
    dp[1][1] = 1;
    for (int s = 1; s < 1 << n; s++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!((s >> (i - 1)) & 1))
                continue;
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                cnt += g[i][j] & !((s >> (j - 1)) & 1);
            if (!cnt)
            {
                add(ans[i],dp[s][i]);
                continue;
            }
            for (int j = 1; j <= n; j++)
                if (g[i][j] & !((s >> (j - 1)) & 1))
                    add(dp[s | (1 << (j - 1))][j],inv[cnt] * dp[s][i]);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i]);
    return 0;
}