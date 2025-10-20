#include<bits/extc++.h>
#define int long long
#define nxt(i) ((i + 1) <= n ? i + 1 : 1)
using namespace std;
int n;
bool vis[25];
int p[25],a[25],b[25];
int __lcm(int x,int y){return x * y / __gcd(x,y);}
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
    x = (x * c % b + b) % b;
    return 1;
}
signed main()
{
    scanf("%lld",&n);
    int pos = 0;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        p[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        while (pos != p[i])
        {
            pos = nxt(pos);
            b[i] += !vis[pos];
        }
        a[i] = n - i + 1;
        vis[p[i]] = 1;
    }
    int mod = a[1],ans = b[1];
    for (int i = 2; i <= n; i++)
    {
        int p,q;
        if (!calc(mod,a[i],b[i] - ans,p,q))
            return printf("NIE"),0;
        ans += mod * p;
        mod = __lcm(mod,a[i]);
    }
    int tmp = (ans % mod + mod) % mod;
    printf("%lld",tmp ? tmp : mod);
    return 0;
}