#include<bits/extc++.h>
using namespace std;
typedef long double ld;
int m,n;
ld binpow(ld x,int y)
{
    ld res = 1.0;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res *= x;
        x *= x;
    }
    return res;
}
signed main()
{
    cin >> m >> n;
    ld ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (binpow((ld)i / m,n) - binpow(ld(i - 1) / m,n)) * i;
    cout << fixed << setprecision(6) << ans;
    return 0;
}