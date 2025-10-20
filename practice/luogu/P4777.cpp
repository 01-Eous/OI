#include<bits/extc++.h>
#define int __int128_t
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],b[maxn];
inline int __lcm(int x,int y)
{return x * y / __gcd(x,y);}
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
    if (x > 10)
        write(x / 10);
    putchar('0' + x % 10);
}
void exgcd(int a,int b,int &x,int &y)
{
    if (!b)
    {
        x = 1,y = 0;
        return;
    }
    exgcd(b,a % b,x,y);
    int tmp = x;
    x = y,y = tmp - a / b * y;
}
bool calc(int a,int b,int c,int &x,int &y)
{
    int g = __gcd(a,b);
    if (c % g)
        return 0;
    a /= g,b /= g,c /= g;
    exgcd(a,b,x,y);
    x = (x * c) % b;
    return 1;
}
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(),b[i] = read();
    int a1 = a[1],b1 = b[1];
    for (int i = 2; i <= n; i++)
    {
        int p,q;
        calc(a1,a[i],b[i] - b1,p,q);
        b1 = a1 * p + b1;
        a1 = __lcm(a1,a[i]);
    }
    write((b1 % a1 + a1) % a1);
    return 0;
}