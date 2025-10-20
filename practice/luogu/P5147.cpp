#include<bits/extc++.h>
using namespace std;
int n;
signed main()
{
    scanf("%d",&n);
    if (n == 1)
        return printf("0.00000"),0;
    double ans = 1;
    if (n <= 1e6)
        for (int i = 1; i < n; i++)
            ans += 1.0 / i;
    else
        ans += log(n) + 0.57721566490153286;
    printf("%.5lf",ans);
    return 0;
}