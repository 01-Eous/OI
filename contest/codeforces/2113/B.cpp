#include<bits/extc++.h>
using namespace std;
int w,h,a,b;
int sx1,sx2,tx1,tx2;
int sy1,sy2,ty1,ty2;
bool bound(int s,int t,int x){return s <= x && x <= t;}
void solve()
{
    scanf("%d%d%d%d",&a,&b,&w,&h);
    scanf("%d%d%d%d",&sx1,&sy1,&sx2,&sy2);
    tx1 = sx1 + w - 1,tx2 = sx2 + w - 1;
    ty1 = sy1 + h - 1,ty2 = sy2 + h - 1;
    bool f1 = 0,f2 = 0;
    if (sy1 < sy2 && (sy2 - ty1 - 1) % h == 0)
        f1 = 1;
    if (sy1 > sy2 && (sy1 - ty2 - 1) % h == 0)
        f1 = 1;
    if (sx1 < sx2 && (sx2 - tx1 - 1) % w == 0)
        f2 = 1;
    if (sx1 > sx2 && (sx1 - tx2 - 1) % w == 0)
        f2 = 1;
    if (f1 || f2)
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