#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k,x;
priority_queue<int> q;
void solve()
{
    scanf("%lld%lld",&n,&k);
    while (!q.empty())
        q.pop();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",&x);
        q.push(x);
        if ((n - i + 1) % (k + 1) == 0)
        {
            ans += q.top();
            q.pop();
        }
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