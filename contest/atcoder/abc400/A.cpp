#include<bits/extc++.h>
signed main()
{
    int a;
    scanf("%d",&a);
    if (400 % a)
        printf("-1");
    else
        printf("%d",400 / a);
    return 0;
}