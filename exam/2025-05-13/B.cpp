#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
#define add(x,y) (x = (x + y) % mod)
using namespace std;
const int mod = 1e9 + 7;
int n,m,sum,tot;
int a[1005][1005];
int sumr[1005],sumc[1005],totr[1005],totc[1005];
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
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld",&a[i][j]);
            add(sum,a[i][j]);
            add(sumr[i],a[i][j]);
            add(sumc[j],a[i][j]);
        }
    }
    if (n == 1)
    {
        int val = a[1][1];
        for (int i = 2; i <= m; i++)
            if (a[1][i] != val)
                return printf("-1"),0;
        puts("1");
        for (int i = 2; i <= m; i++)
            printf("0 ");
        printf("%lld",val);
        return 0;
    }
    else if (m == 1)
    {
        int val = a[1][1];
        for (int i = 2; i <= n; i++)
            if (a[i][1] != val)
                return printf("-1"),0;
        puts("1");
        for (int i = 2; i <= n; i++)
            printf("\n0");
        printf("%lld",val);
        return 0;
    }
    tot = sum * inv(n + m - 1) % mod;
    for (int i = 1,_inv = inv(m - 1); i <= n; i++)
        totr[i] = (sumr[i] - tot + mod) % mod * _inv % mod;
    for (int i = 1,_inv = inv(n - 1); i <= m; i++)
        totc[i] = (sumc[i] - tot + mod) % mod * _inv % mod;
    puts("1");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%lld%c",(totr[i] + totc[j] - a[i][j] + mod) % mod," \n"[j == m]);
    return 0;
}