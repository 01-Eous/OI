#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,c,d;
void exgcd(int a,int b,int c,int d,int &x,int &y)
{
    if (a < b && c > d)
    {
        x = y = 1;
        return;
    }
    exgcd(d % c,c,b - (d / c) * a,a,y,x);
    y += (d / c) * x;
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        int x,y;
        exgcd(a,b,c,d,x,y);
        printf("%lld\n",y);
    }
    return 0;
}   