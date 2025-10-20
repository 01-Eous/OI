#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
int n,m;
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
void read(int &x)
{
    char ch;x = 0;
    while (!isdigit(ch = getchar()));
    while (isdigit(ch)){x = (x * 10 + ch - '0') % mod; ch = getchar();}
}
signed main()
{
    read(n),read(m);
    printf("%lld\n",binpow(m,mod - 2) * n % mod);
    return 0;
}