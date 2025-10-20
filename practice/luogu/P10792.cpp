#include<bits/extc++.h>
#define int __int128_t
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 2007072007;
int m;
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}
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
    m = read();
    int sum = 0,n = 0;
    for (int i = 1,x,l; i <= m; i++)
    {
        x = read(),l = read();
        n += l;
        sum = (sum + x * l) % mod;
    }
    sum = sum * (binpow(10,n) - 1) % mod * inv(9) % mod;
    write(sum * inv(n) % mod);
    putchar('\n');
}
signed main()
{
    signed t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}