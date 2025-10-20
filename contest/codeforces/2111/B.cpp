#include<bits/extc++.h>
using namespace std;
int n,m;
int f[15];
void init()
{
    f[1] = 1,f[2] = 2;
    for (int i = 3; i <= 10; i++)
        f[i] = f[i - 1] + f[i - 2];
}
void solve()
{
    scanf("%d%d",&n,&m);
    int a[3];
    while (m--)
    {
        scanf("%d%d%d",a + 0,a + 1,a + 2);
        sort(a,a + 3,greater<int>());
        if (a[0] >= f[n] + f[n - 1] && a[1] >= f[n] && a[2] >= f[n])
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}
signed main()
{
    init();
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}