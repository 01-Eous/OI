#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 1e9 + 7;
int w,n,k;
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    cin >> w >> n >> k;
    cout << w * inv(binpow(2,k)) % mod;
    return 0;
}