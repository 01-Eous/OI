#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int c[maxn],w[maxn],lst[maxn];
int sumc[maxn],sumw[maxn],dp[maxn],_min[maxn];
queue<int> q[maxn];
signed main()
{
    scanf("%lld%lld",&n,&k);
    if (k == 1)
        return printf("0"),0;
    for (int i = 1; i <= n; i++)
        scanf("%lld",c + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",w + i);
        sumc[i] = sumc[lst[c[i]]] + w[i];
        sumw[i] = sumw[i - 1] + w[i];
        lst[c[i]] = i;
    }
    memset(_min,0x3f,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + w[i];
        if (q[c[i]].size() == k - 1)
        {
            int j = q[c[i]].front();
            _min[c[i]] = min(_min[c[i]],dp[j - 1] - sumw[j - 1] + sumc[j] - w[j]);
            q[c[i]].pop();
        }
        dp[i] = min(dp[i],_min[c[i]] + sumw[i] - sumc[i]);
        q[c[i]].push(i);
    }
    printf("%lld",dp[n]);
    return 0;
}