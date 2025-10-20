#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,c,d;
int gcd(int c,int d)
{
    int res = 0,tmp;
    while (1)
    {
        bool fl = 0;
        tmp = (d - b) / c;
        if (tmp)
        {
            fl = 1;
            res += tmp;
            d -= tmp * c;
        }
        tmp = (c - a) / d;
        if (tmp)
        {
            fl = 1;
            res += tmp;
            c -= tmp * d;
        }
        if (c == a && d == b)
            break;
        if (!fl)
            return -1;
    }
    return res;
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if (a > c || b > d)
        {
            puts("-1");
            continue;
        }
        if (c > d)
            swap(a,b),swap(c,d);
        printf("%lld\n",gcd(c,d));
    }
    return 0;
}