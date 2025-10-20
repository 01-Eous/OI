#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
bool calc(int x)
{
    if ((n / x - 1) % (x + 1))
        return 0;
    if ((n / x - 1) / (x + 1) <= 0)
        return 0;
    return 1;
}
void solve()
{
    scanf("%lld",&n);
    bool ans = 0;
    for (int i = 1; i * i <= n && !ans; i++)
    {
        if (n % i == 0)
        {
            ans |= calc(i);
            ans |= calc(n / i);
        }
    }
    printf("%lld\n",(int)ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}