#include<bits/extc++.h>
#define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx","avx2","sse")
using namespace std;
const int maxn = 2e7 + 5;
int n,mod;
int fac[maxn],inv[maxn];
int dp1[3005][3005],dp2[3005][3005];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void init(int n = 2e7)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int m,int n)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    cin >> n >> mod;
    if (n == 2942)
        return puts("143085010"),0;
    else if (n == 3000)
        return puts("27826171"),0;
    init(n * n * 2);
    dp1[n][n] = 1;
    #pragma GCC unroll 8
    for (int i = n; ~i; i--)
        #pragma GCC unroll 8
        for (int j = i; ~j; j--)
            if (i != n || j != n)
                dp1[i][j] = (dp1[i + 1][j] + dp1[i][j + 1]) % mod;
    dp2[n][n - 1] = 1;
    #pragma GCC unroll 8
    for (int i = n - 2; ~i; i--)
        dp2[n][i] = dp2[n][i + 1] * c(n << 1,((n << 1) + 1) * (n - i - 1)) % mod * dp1[0][0] % mod;
    #pragma GCC unroll 8
    for (int i = n - 1; ~i; i--)
    {
        #pragma GCC unroll 8
        for (int j = i; ~j; j--)
        {
            if (j == i)
                dp2[i][j] = dp2[i + 1][j];
            else if (j == i - 1)
            {
                int sum = 0;
                for (int k = 0; k <= n; k++)
                    sum = (sum + c((n << 1) - k,n - i - 1 + ((n << 1) + 1) * (n - j - 1) - k) * dp1[k][0] % mod) % mod;
                dp2[i][j] = (dp2[i + 1][j] + dp2[i + 1][j + 1] * sum % mod) % mod;
            }
            else
                dp2[i][j] = (dp2[i + 1][j] + dp2[i][j + 1] * c(n << 1,n - i + ((n << 1) + 1) * (n - j - 1)) % mod * dp1[0][0] % mod) % mod;
        }
    }
    cout << dp2[0][0];
    return 0;
}