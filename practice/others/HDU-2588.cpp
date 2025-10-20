#include<bits/extc++.h>
using namespace std;
int n,m;
int phi(int x)
{
    int res = x,up = x;
    for (int i = 2; i * i <= up; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}
void solve()
{
    scanf("%d%d",&n,&m);
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int x = i,y = n / i;
            if (x >= m)
                ans += phi(y);
            if (x != y && y >= m)
                ans += phi(x);
        }
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}