#include<bits/extc++.h>
using namespace std;
int k,a,b,x,y;
void solve()
{
    scanf("%d%d%d%d%d",&k,&a,&b,&x,&y);
    if (x > y)
        swap(a,b),swap(x,y);
    int ans = 0,tmp;
    tmp = max(0.0,ceil((k - a + 1.0) / x));
    ans += tmp,k -= tmp * x;
    tmp = max(0.0,ceil((k - b + 1.0) / y));
    ans += tmp,k -= tmp * y;
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}