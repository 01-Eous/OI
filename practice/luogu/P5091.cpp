#include<bits/extc++.h>
#define int long long
using namespace std;
int a,mod,b,p,idx;
char s[20000005];
int phi(int x)
{
    int up = x,res = x;
    for (int i = 2; i * i <= up; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        res = res / x * (x - 1);
    return res;
}
int read()
{
    int x = 0;
    char ch = s[++idx];
    while (!isdigit(ch)){ch = s[++idx];}
    while (isdigit(ch)){x = (x * 10 + (ch ^ 48)) % p; ch = s[++idx];}
    return x;
}
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld%s",&a,&mod,s + 1);
    if (strlen(s + 1) <= 18)
        sscanf(s + 1,"%lld",&b);
    else
    {
        p = phi(mod);
        b = read();
    }
    printf("%lld",binpow(a,b + p));
    return 0;
}