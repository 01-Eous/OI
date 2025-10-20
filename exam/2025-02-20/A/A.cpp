#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,a[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    double ans = 1;
    for (int i = 2; i <= n; i++)
        ans += (double)a[i] / (a[1] + a[i]);
    printf("%.10lf",ans);
    return 0;
}