#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
bool ipr[1005];
int a[maxn],sum[maxn],dp[maxn][200],f[200];
vector<int> pr,fac[maxn];
void prime(int up = 1000)
{
    for (int i = 2; i <= up; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (i * j > up)
                break;
            ipr[i * j] = 1;
            if (i % j == 0)
                break;
        }
    }
}
signed main()
{
    prime();
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        sum[i] = sum[i - 1] + (a[i] > 1);
        if (!a[i])
            continue;
        for (int j = 0; j < pr.size(); j++)
            if (a[i] % pr[j] == 0)
                fac[i].push_back(j);
    }
    fill(f,f + pr.size(),n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (!a[i])
        {
            fill(f,f + pr.size(),i);
            fill(dp[i],dp[i] + pr.size(),i);
        }
        else
        {
            fill(dp[i],dp[i] + pr.size(),n + 1);
            for (auto j : fac[i])
            {
                if (f[j] != n + 1)
                    for (int k = 0; k < pr.size(); k++)
                        dp[i][k] = min(dp[i][k],dp[f[j]][k]);
                dp[i][j] = f[j] = i;
            }
        }
    }
    int u,v;
    while (q--)
    {
        scanf("%d%d",&u,&v);
        if (u == v)
        {
            puts("Shi");
            continue;
        }
        if (!a[v] && a[u] > 1)
        {
            puts("Shi");
            continue;
        }
        if (!a[u] && !a[v] && sum[v] - sum[u - 1] > 0)
        {
            puts("Shi");
            continue;
        }
        int _min = n + 1;
        for (auto j : fac[v])
            _min = min(_min,dp[u][j]);
        puts(_min <= v ? "Shi" : "Fou");
    }
    return 0;
}