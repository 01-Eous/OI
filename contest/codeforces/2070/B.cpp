#include<bits/extc++.h>
#define int long long 
using namespace std;
int n,x,k;
char s[200005];
void solve()
{
    scanf("%lld%lld%lld%s",&n,&x,&k,s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
            x--;
        else
            x++;
        k--;
        if (x == 0)
            break;
    }
    if (x)
        return (void)puts("0");
    int stp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
            x--;
        else
            x++;
        stp++;
        if (!x)
            break;
    }
    if (x)
        return (void)puts("1");
    printf("%lld\n",k / stp + 1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}