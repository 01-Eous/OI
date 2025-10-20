#include<bits/extc++.h>
#define int long long
using namespace std;
int x,y;
int calc(int l,int r){return (l + r) * (r - l + 1) >> 1;}
int g(int n)
{
    int res = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = min(n,n / (n / l));
        res += calc(l,r) * (n / l);
    }
    return res;
}
signed main()
{
    scanf("%lld%lld",&x,&y);
    printf("%lld",g(y) - g(x - 1));
    return 0;
}