#include<bits/extc++.h>
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
    while (scanf("%d%d%d%d",&a,&b,&c,&d) != EOF)
    {
        int x,y;
        exgcd(a,b,c,d,x,y);
        printf("%d/%d\n",x,y);
    }
    return 0;
}