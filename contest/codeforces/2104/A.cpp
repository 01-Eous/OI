#include<bits/extc++.h>
using namespace std;
int a,b,c;
void solve()
{
    scanf("%d%d%d",&a,&b,&c);
    int x = (a + b + c) / 3;
    if (a > x || b > x || c < x)
        puts("NO");
    else if (x - a + x - b != c - x)
        puts("NO");
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