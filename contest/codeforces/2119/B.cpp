#include<bits/extc++.h>
#define sq(x) (1LL * (x) * (x))
using namespace std;
using ld = long double;
const ld eps = 1e-12;
int n;
ld dis,x;
int sx,sy,tx,ty;
void solve()
{
    scanf("%d%d%d%d%d",&n,&sx,&sy,&tx,&ty);
    dis = sqrt(sq(sx - tx) + sq(sy - ty));
    ld sum = 0,min1 = 0,max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%Lf",&x);
        sum += x;
        max1 = max(max1,x);
    }
    min1 = max1 * 2 - sum;
    if (sum - dis > -eps && dis - min1 > -eps)
        puts("Yes");
    else
        puts("No");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}