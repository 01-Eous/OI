#include<bits/extc++.h>
using namespace std;
int n;
int a[105];
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (a[i] > a[j])
                return (void)printf("YES\n2\n%d %d\n",a[i],a[j]);
    puts("NO");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}