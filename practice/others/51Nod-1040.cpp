#include<bits/extc++.h>
using namespace std;
using ll = long long;
int n;
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
signed main()
{
    scanf("%d",&n);
    ll ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int x = i,y = n / i;
            ans += (ll)phi(x) * y;
            if (x != y)
                ans += (ll)phi(y) * x;
        }
    }
    printf("%lld",ans);
    return 0;
}