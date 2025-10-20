#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],sum[maxn];
bool check(int x)
{
    vector<int> dp(n + 5,inf);
    deque<int> q;
    dp[0] = 0,q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && sum[i - 1] - sum[q.front()] > x)
            q.pop_front();
        dp[i] = dp[q.front()] + a[i];
        while (!q.empty() && dp[i] < dp[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (int j = n; j >= 1; j--)
    {
        if (sum[n] - sum[j] > x)
            break;
        if (dp[j] <= x)
            return 1;   
    }
    return 0;
}
void solve()
{
    scanf("%lld",&n);
    int l = 0,r = 0,mid,ans = inf;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        l = max(l,a[i]);
        r += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}