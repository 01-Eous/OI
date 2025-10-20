#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
int a[maxn];
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    int l = a[(n - k + 1) >> 1];
    int r = a[k + ((n - k) >> 1) + 1];
    printf("%d\n",r - l + 1);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}