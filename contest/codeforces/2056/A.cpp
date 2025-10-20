#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,x,y;
int r,c;
void solve()
{
    scanf("%lld%lld",&n,&m);
    r = c = m;
    n--;
    scanf("%lld%lld",&x,&y);
    while (n--)
    {
        scanf("%lld%lld",&x,&y);
        r += x,c += y;
    }
    printf("%lld\n",(r + c) << 1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}