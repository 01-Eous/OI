#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,x,y;
void solve()
{
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    if (a > b)
    {
        if ((a ^ b) == 1)
            printf("%lld\n",y);
        else
            puts("-1");
        return;
    }
    int ans = 0;
    while (a != b)
    {
        if (a & 1)
            ans += x;
        else
            ans += min(x,y);
        a++;
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