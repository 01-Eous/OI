#include<bits/extc++.h>
using namespace std;
int n,k;
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n - 2; i++)
        printf("%d ",n - !(k & 1));
    printf("%d %d\n",n,n - 1);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}