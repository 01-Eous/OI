#include<bits/extc++.h>
using namespace std;
const int maxn = 105;
int n;
inline void solve()
{
    scanf("%d",&n);
    if (n == 6)
    {
        puts("1 1 2 3 1 2");
        return;
    }
    for (int i = 1; i <= (n + 1) >> 1; i++)
        printf("%d ",i);
    for (int i = 1; i <= n - ((n + 1) >> 1); i++)
        printf("%d ",i);
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