#include<bits/extc++.h>
#define int long long
using namespace std;
using ld = double;
int n,m;
ld val,ans;
signed main()
{
    scanf("%lld%lld%lf",&n,&m,&val);
    ans = val;
    int a = 0,b = 1,c = 1,d = 0;
    int ax = 0,ay = 1,x,y;
    bool fl = 0;
    while (1)
    {
        x = a + c,y = b + d;
        if (x > n || y > m)
            break;
        ld cur = fabs((ld)x / y - val);
        if (cur == ans)
            fl = 1;
        else if (cur < ans)
        {
            ax = x,ay = y;
            ans = cur,fl = 0;
            if (ans == 0)
                break;
        }
        if ((ld)x / y < val)
            a = x,b = y;
        else
            c = x,d = y;
    }
    if (fl)
        puts("TOO MANY");
    else
        printf("%lld/%lld",ax,ay);
    return 0;
}