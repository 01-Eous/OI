#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,m,d;
int a[305],s[maxn],dp[305][maxn];
signed main()
{
    freopen("climb.in","r",stdin);
    freopen("climb.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        s[++m] = a[i];
        for (int j = 1; j <= n; j++)
            s[++m] = a[i] + d * j;
        for (int j = -1; j >= -n && a[i] + d * j >= 0; j--)
            s[++m] = a[i] + d * j;
    }
    if (abs(a[n] - a[1]) > (n - 1) * d)
        return printf("-1"),0;
    sort(s + 1,s + m + 1);
    m = unique(s + 1,s + m + 1) - s - 1;
    memset(dp,0x3f,sizeof(dp));
    dp[1][lower_bound(s + 1,s + m + 1,a[1]) - s] = 0;
    for (int i = 2; i < n; i++)
    {
        deque<int> q;
        for (int j = 1,p = 0; j <= m; j++)
        {
            while (p <= m && s[p + 1] <= s[j] + d)
            {
                p++;
                while (!q.empty() && dp[i - 1][q.back()] > dp[i - 1][p])
                    q.pop_back();
                q.push_back(p);
            }
            while (!q.empty() && s[q.front()] < s[j] - d)
                q.pop_front();
            if (!q.empty())
                dp[i][j] = dp[i - 1][q.front()] + abs(s[j] - a[i]);
        }
    }
    int ans = inf;
    for (int i = 1; i <= m; i++)
        if (abs(a[n] - s[i]) <= d)
            ans = min(ans,dp[n - 1][i]);
    printf("%lld",ans);
    return 0;
}