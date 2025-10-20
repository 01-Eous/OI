#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inv2 = 500000004;
const int inv6 = 166666668;
int n;
int dp[405];
int c(int n,int m)
{
    if (m == 2)
        return n * (n - 1) % mod * inv2 % mod;
    else
        return n * (n - 1) % mod * (n - 2) % mod * inv6 % mod;
}
signed main()
{
    scanf("%lld",&n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < i; x++)
        {
            for (int y = x; i - x - y > y; y++)
            {
                int z = i - 1 - x - y;
                if (x == z)
                    dp[i] = (dp[i] + c(dp[x] + 2,3)) % mod;
                else if (x == y)
                    dp[i] = (dp[i] + c(dp[x] + 1,2) * dp[z]) % mod;
                else if (y == z)
                    dp[i] = (dp[i] + c(dp[y] + 1,2) * dp[x]) % mod;
                else
                    dp[i] = (dp[i] + dp[x] % mod * dp[y] % mod * dp[z]) % mod;
            }
        }
    }
    printf("%lld",dp[n]);
    return 0;
}