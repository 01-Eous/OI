#include<bits/extc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n,x;
signed main()
{
    scanf("%d",&n);
    int sum = 0;
    while (n--)
    {
        scanf("%d",&x);
        sum ^= x;
    }
    printf("%d",sum);
    return 0;
}