#include<bits/extc++.h>
using namespace std;
int x,c,k;
signed main()
{
    scanf("%d%d%d",&x,&c,&k);
    k--;
    while (k--)
        x = (x * x + c) % 10000;
    cout << x;
    return 0;
}