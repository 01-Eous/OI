#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
signed main()
{
    scanf("%lld",&n);
    int sum = 0,ans = 0;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        ans += x * sum;
        sum += x;
    }
    printf("%lld",ans);
    return 0;
}