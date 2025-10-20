#include<bits/extc++.h>
#define sq(x) ((x) * (x))
using namespace std;
const double st = 1e5,ed = 1e-12,d = 0.995;
mt19937 rnd(random_device{}());
int n,m;
int a[25],sum[25];
double dp[25][10],avg,ans;
double calc()
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < i; k++)
                dp[i][j] = min(dp[i][j],dp[k][j - 1] + sq(sum[i] - sum[k] - avg));
    ans = min(ans,dp[n][m]);
    return dp[n][m];
}
void SA()
{
    double lst = ans;
    for (double t = st; t > ed; t *= d)
    {
        int x = rnd() % n + 1,y = rnd() % n + 1;
        while (x == y)
            x = rnd() % n + 1,y = rnd() % n + 1;
        swap(a[x],a[y]);
        double cur = calc(),dlt = cur - lst;
        if (dlt < 0 || exp(dlt) / t > rnd() / (double)rnd.max())
            lst = cur;
        else
            swap(a[x],a[y]);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i),avg += a[i];
    avg /= m,ans = calc();
    while (clock() < CLOCKS_PER_SEC * 0.9)
        SA();
    printf("%.2lf",sqrt(ans / m));
    return 0;
}