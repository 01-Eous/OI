#include<bits/extc++.h>
#define int long long
using namespace std;
const int pw[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000,
    1000000000000000000
};
int a1,a2,a3,x,y;
void solve()
{
    scanf("%lld%lld%lld",&a1,&a2,&a3);
    bool fl = 0;
    if (a1 > a2)
        swap(a1,a2),fl = 1;
    if (a3 < a2 || a3 > a1 + a2)
        return (void)puts("No");
    if (a1 + a2 == a3)
        x = pw[a1 - 1] << 3 | 1,y = pw[a2 - 1] << 3;
    else
        x = pw[a1 - 1],y = pw[a2] - pw[a1 + a2 - a3 - 1];
    if (fl)
        swap(x,y);
    printf("Yes\n%lld %lld\n",x,y);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}