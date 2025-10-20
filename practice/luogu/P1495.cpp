#include<bits/extc++.h>
#define int long long
using namespace std;
using i128 = __int128;
int n;
int r[15],a[15];
void exgcd(int a,int b,i128 &x,i128 &y)
{
    if (!b)
    {
        x = 1,y = 0;
        return;
    }
    exgcd(b,a % b,y,x);
    y -= a / b * x;
}
signed main()
{
    scanf("%lld",&n);
    i128 mul = 1,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",r + i,a + i);
        mul *= (i128)r[i];
    }
    for (int i = 1; i <= n; i++)
    {
        i128 tmp = mul / r[i],inv,y;
        exgcd(tmp,r[i],inv,y);
        ans = (ans + a[i] * tmp * inv % mul) % mul;
    }
    printf("%lld",(int)((ans % mul + mul) % mul));
    return 0;
}