#include<bits/extc++.h>
using namespace std;
using ll = long long;
int n,m,k;
int a[1005];
class long_int
{
    private:
    static const ll base = 1e6;
    int len;
    ll d[25];

    public:
    long_int(ll x = 0)
    {
        memset(d,0,sizeof(d));
        len = 0;
        while (x)
        {
            d[++len] = x % base;
            x /= base;
        }
    }
    friend bool operator<(const long_int &x,const long_int &y)
    {
        if (x.len < y.len)
            return 1;
        if (x.len > y.len)
            return 0;
        for (int i = x.len; i >= 1; i--)
        {
            if (x.d[i] < y.d[i])
                return 1;
            if (x.d[i] > y.d[i])
                return 0;
        }
        return 0;
    }
    friend long_int operator*(const long_int &x,const long_int &y)
    {
        long_int res(0);
        res.len = x.len + y.len - 1;
        for (int i = 1; i <= x.len; i++)
            for (int j = 1; j <= y.len; j++)
                res.d[i + j - 1] += x.d[i] * y.d[j];
        for (int i = 1; i <= res.len; i++)
        {
            res.d[i + 1] += res.d[i] / base;
            res.d[i] %= base;
        }
        if (res.d[res.len + 1])
            res.len++;
        return res;
    }
    void out()
    {
        printf("%lld",d[len]);
        for (int i = len - 1; i >= 1; i--)
            printf("%06lld",d[i]);
    }
}dp[1005][1030];
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < 1 << m; s++)
        {
            dp[i][s] = dp[i - 1][s];
            for (int j = 0; j < m; j++)
                if ((s >> j) & 1)
                    dp[i][s] = max(dp[i][s],dp[max(0,i - k)][s ^ (1 << j)] * (a[i] - j));
        }
    }
    long_int ans = 0;
    for (int s = 0; s < 1 << m; s++)
        ans = max(ans,dp[n][s]);
    ans.out();
    return 0;
}