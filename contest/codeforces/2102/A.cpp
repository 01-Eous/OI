#include<bits/extc++.h>
using namespace std;
int n,m,p,q;
void solve()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);
    if (n % p == 0)
    {
        if (m % q || m / q != n / p)
            puts("NO");
        else
            puts("YES");
    }
    else
        puts("YES");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}