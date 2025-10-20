#include<bits/extc++.h>
using namespace std;
int n,m;
void solve()
{
    scanf("%d%d",&n,&m);
    vector<basic_string<int>>a(n + 5,basic_string<int>(m + 5,-1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);
        a[i][m + 1] = i;
        sort(a[i].begin() + 1,a[i].begin() + m + 1);
    }
    sort(a.begin() + 1,a.begin() + n + 1);
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((i == 1 && a[n][j - 1] > a[i][j]) || (i != 1 && a[i - 1][j] > a[i][j]))
            {
                puts("-1");
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ",a[i][m + 1]);
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