#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn],ans[maxn];
priority_queue<int>q;
signed main()
{
    scanf("%lld",&n);
    scanf("%lld",a + 1);
    q.push(a[1] -= 1);
    ans[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld",a + i);
        q.push(a[i] -= i);
        if (q.top() > a[i])
        {
            q.pop();
            q.push(a[i]);
        }
        ans[i] = q.top();
    }
    int sum = 0;
    for (int i = n - 1; i >= 1; i--)
        ans[i] = min(ans[i],ans[i + 1]);
    for (int i = 1; i <= n; i++)
        sum += abs(a[i] - ans[i]);
    printf("%lld\n",sum);
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i] + i);
    return 0;
}