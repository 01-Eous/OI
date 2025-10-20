#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
const int maxn = 1e4 + 5;
int sh,sm,th,tm;
int n,m,w[maxn],c[maxn],p[maxn],dp[1005];
signed main()
{
    scanf("%d:%d %d:%d",&sh,&sm,&th,&tm);
    m = (th - sh) * 60 + (tm - sm);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d",w + i,c + i,p + i);
    for (int i = 1; i <= n; i++)
    {
        if (p[i])
        {
            for (int j = m; j >= w[i]; j--)
                for (int k = 1; k * w[i] <= j && k <= p[i]; k++)
                    dp[j] = max(dp[j],dp[j - k * w[i]] + k * c[i]);
        }
        else
            for (int j = w[i]; j <= m; j++)
                dp[j] = max(dp[j],dp[j - w[i]] + c[i]);
    }
    printf("%d",dp[m]);
    return 0;
}