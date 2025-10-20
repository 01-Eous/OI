#include<bits/extc++.h>
using namespace std;
int n,m,k;
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    int mod;
    if (n < (m + 1) * k)
        mod = k;
    else
        mod = n / (m + 1);
    for (int i = 0; i < n; i++)
        printf("%d ",i % mod);
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