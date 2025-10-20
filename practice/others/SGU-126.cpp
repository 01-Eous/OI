#include<bits/extc++.h>
using namespace std;
int a,b;
signed main()
{
    scanf("%d%d",&a,&b);
    int tmp = (a + b) / gcd(a,b),ans = 0;
    while (!(tmp & 1))
        ans++,tmp >>= 1;
    printf("%d",tmp == 1 ? ans : -1);
    return 0;
}