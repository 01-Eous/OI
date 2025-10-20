#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int h(int n)
{
    int res = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res += (r - l + 1) * (n / l);
    }
    return res;
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",h(n));
    }
    return 0;
}