#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,q,m;
int a[maxn],dp[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&m);
        dp[1] = 0;
        deque<int> q = {1};
        for (int i = 2; i <= n; i++)
        {
            while (!q.empty() && q.front() < i - m)
                q.pop_front();
            int j = q.front();
            if (a[j] > a[i])
                dp[i] = dp[j];
            else
                dp[i] = dp[j] + 1;
            while (!q.empty() && (dp[q.back()] > dp[i] || (dp[q.back()] == dp[i] && a[q.back()] <= a[i])))
                q.pop_back();
            q.push_back(i);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}