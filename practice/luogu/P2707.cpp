#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,k;
int a[maxn],b[maxn],cur[maxn];
priority_queue<pii,vector<pii>> q;
int calc(int i,int val)
{
    int x = max(a[i] - b[i] * val,0LL) * val++;
    int y = max(a[i] - b[i] * val,0LL) * val;
    return y - x;
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",a + i,b + i);
        q.push({calc(i,cur[i] = 0),i});
    }
    int ans = 0;
    while (k-- && q.top().first > 0)
    {
        int i = q.top().second;
        ans += q.top().first,q.pop();
        q.push({calc(i,++cur[i]),i});
    }
    printf("%lld",ans);
    return 0;
}