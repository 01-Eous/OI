#include<bits/extc++.h>
using namespace std;
int n;
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int ans = n / 15 * 3 + min(3,n - (n / 15 * 15) + 1);
        printf("%d\n",ans);
    }
    return 0;
}