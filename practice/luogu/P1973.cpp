#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define calc(y) min(x + y + tot[i][j],dp1[i][x] + dp2[j][y])
using namespace std;
int n;
int st[505],en[505];
int rnk[505],idx;
int tot[505][505];
int dp1[505][505],dp2[505][505],dp[505][505];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",st + i,en + i);
        rnk[++idx] = st[i];
        rnk[++idx] = (en[i] += st[i]);
    }
    sort(rnk + 1,rnk + idx + 1);
    idx = unique(rnk + 1,rnk + idx + 1) - rnk - 1;
    for (int i = 1; i <= n; i++)
    {
        st[i] = lower_bound(rnk + 1,rnk + idx + 1,st[i]) - rnk;
        en[i] = lower_bound(rnk + 1,rnk + idx + 1,en[i]) - rnk;
        for (int j = 1; j <= st[i]; j++)
            for (int k = en[i]; k <= idx; k++)
                tot[j][k]++;
    }
    for (int i = 1; i <= idx; i++)
    {
        fill(dp1[i] + 1,dp1[i] + n + 1,-inf);
        fill(dp2[i] + 1,dp2[i] + n + 1,-inf);
    }
    for (int i = 1; i <= idx; i++)
    {
        for (int j = 0; j <= tot[1][i]; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                dp1[i][j] = max(dp1[i][j],dp1[k][j] + tot[k][i]);
                if (j >= tot[i][k])
                    dp1[i][j] = max(dp1[i][j],dp1[k][j - tot[k][i]]);
            }
        }
    }
    for (int i = idx; i >= 1; i--)
    {
        for (int j = 0; j <= tot[i][idx]; j++)
        {
            for (int k = i; k <= idx; k++)
            {
                dp2[i][j] = max(dp2[i][j],dp2[k][j] + tot[i][k]);
                if (j >= tot[k][i])
                    dp2[i][j] = max(dp2[i][j],dp2[k][j - tot[i][k]]);
            }
        }
    }
    for (int i = 1; i <= idx; i++)
    {
        for (int j = i + 1; j <= idx; j++)
        {
            for (int x = 0,y = n; x <= n; x++)
            {
                int tmp = calc(y);
                while (y && tmp <= calc(y - 1))
                {
                    y--;
                    tmp = calc(y);
                }
                dp[i][j] = max(dp[i][j],tmp);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans,min(dp1[idx][i],i));
    printf("%d\n",ans);
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= st[i]; j++)
            for (int k = en[i]; k <= idx; k++)
                ans = max(ans,dp[j][k]);
        printf("%d\n",ans);
    }
    return 0;
}