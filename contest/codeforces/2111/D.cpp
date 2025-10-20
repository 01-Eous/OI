#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],ans[maxn][8];
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
        scanf("%d",a + i);
    sort(a + 1,a + m + 1);
    int p[2] = {1,m};
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= 6; j++)
        {
            ans[i][j] = a[p[(i & 1) ^ (j & 1)]];
            ans[i + 1][j] = a[p[(!(i & 1)) ^ (j & 1)]];
        }
        p[0]++,p[1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
            printf("%d ",ans[i][j]);
        putchar('\n');
    }
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}