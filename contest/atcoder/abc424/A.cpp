#include<bits/extc++.h>
using namespace std;
int a,b,c;
signed main()
{
    scanf("%d%d%d",&a,&b,&c);
    if (a == b || b == c || a == c)
        puts("Yes");
    else
        puts("No");
    return 0;
}