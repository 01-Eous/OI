#include<bits/extc++.h>
#define int long long
using namespace std;
int n,x,y;
int calc(int s)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += (s + i) % x;
    return res;
}
signed main()
{
    scanf("%lld%lld%lld",&n,&x,&y);
    if (n >= x)
        return printf("%lld",x - 1),0;
    int ans = 0;
    int l = 0,r = x - n,mid,res = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        int tmp = calc(mid);
        if (tmp < y)
            l = mid + 1;
        else if (tmp > y)
            r = mid - 1;
        else
        {
            res = mid;
            break;
        }
    }
    if (~res)
        ans = res + n - 1;
    l = x - n + 1,r = x - 1,res = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        int tmp = calc(mid);
        if (tmp < y)
            r = mid - 1;
        else if (tmp > y)
            l = mid + 1;
        else
        {
            res = mid;
            break;
        }
    }
    if (~res)
        ans = x - 1;
    printf("%lld",ans);
    return 0;
}