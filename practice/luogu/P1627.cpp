#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn];
unordered_map<int,int> mp[2];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (a[i] < m)
            a[i] = -1;
        else if (a[i] > m)
            a[i] = 1;
        else
            a[i] = 0;
    }
    mp[0][0] = 1;
    int sum = 0,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        ans += mp[!(i & 1)][sum];
        mp[i & 1][sum]++;
    }
    printf("%lld",ans);
    return 0;
}