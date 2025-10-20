#include<bits/extc++.h>
using namespace std;
int n;
int f[105],p[105],l[105];
void exgcd(int a,int b,int &x,int &y)
{
    if (!b)
    {
        x = 1,y = 0;
        return;
    }
    exgcd(b,a % b,x,y);
    int tmp = x;
    x = y,y = tmp - a / b * y;
}
bool chk(int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int a = p[j] - p[i],b = m,c = f[i] - f[j],x,y;
            int tmp = __gcd(a,b);
            if (c % tmp)
                continue;
            a /= tmp,b /= tmp,c /= tmp;
            exgcd(a,b,x,y);
            b = abs(b);
            x = (x * c % b - b) % b + b;
            if (x <= min(l[i],l[j]))
                return 0;
        }
    }
    return 1;
}
signed main()
{
    scanf("%d",&n);
    int max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",f + i,p + i,l + i);
        max1 = max(max1,f[i]);
    }
    for (int i = max1; ; i++)
       if (chk(i))
           return printf("%d",i),0;
    return 0;
}
