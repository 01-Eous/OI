#include<bits/extc++.h>
using namespace std;
int n,k;
void solve()
{
    scanf("%d%d",&n,&k);
    if (k > (n >> 1))
        return (void)puts("NO");
    puts("YES");
    printf("1 ");
    for (int i = n; i >= (k << 1 | 1); i--)
        printf("%d ",i);
    for (int i = 1; i <= (k << 1); i += 2)
        for (int j = max(2,i); j <= (k << 1); j <<= 1)
            printf("%d ",j);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}