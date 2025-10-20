#include<bits/extc++.h>
using namespace std;
int a,b,c;
void solve()
{
    scanf("%d%d%d",&a,&b,&c);
    if (b > c)
        swap(b,c);
    if (a < b || a > c)
        puts("YES");
    else
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