#include<bits/extc++.h>
using namespace std;
int n,k;
int a[1005];
signed main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    int m = (n + 1) >> 1;
    int p = m,ans = a[m];
    while (a[p] == a[m])
        p++;
    if (p - m <= k)
        ans++;
    printf("%d",ans);
    return 0;
}