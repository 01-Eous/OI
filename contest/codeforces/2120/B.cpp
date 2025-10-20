#include<bits/extc++.h>
#define int long long
using namespace std;
int n,s;
int x,y,dx,dy;
void solve()
{
    scanf("%lld%lld",&n,&s);
    int ans = 0;
    while (n--)
    {
        scanf("%lld%lld%lld%lld",&dx,&dy,&x,&y);
        if (dx + dy == 0)
            ans += x + y == s;
        else
            ans += x == y;
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