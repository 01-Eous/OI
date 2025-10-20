#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int mod = 1LL << 31;
int n;
int dp[4005];
signed main()
{
    scanf("%lld",&n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; i + j <= n; j++)
            add(dp[i + j],dp[j]);
    printf("%lld",dp[n] - 1);
    return 0;
}