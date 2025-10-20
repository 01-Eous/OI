#include<bits/extc++.h>
using namespace std;
const int mod = 9973;
int a,b;
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void solve()
{
    scanf("%d%d",&a,&b);
    printf("%d\n",a * binpow(b % mod,mod - 2) % mod);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}