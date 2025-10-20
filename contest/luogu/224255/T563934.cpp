#include<bits/extc++.h>
using namespace std;
signed main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if (a % 10 <= b)
        printf("%d",b - a % 10);
    else
        printf("%d",10 + b - a % 10);
    return 0;
}