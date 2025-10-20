#include<bits/extc++.h>
#define int __int128_t
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],b[maxn],p[maxn],s[maxn];
multiset<int> st;
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
void solve()
{
    n = read(),m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        p[i] = read();
    for (int i = 1; i <= n; i ++)
        s[i] = read();
    st.clear();
    while (m--)
        st.insert(read());
    int ans = 0,mod = 1,max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        set<int>::iterator it = st.upper_bound(a[i]);
        if (it != st.begin())
            it--;
        b[i] = *it;
        st.erase(it),st.insert(s[i]);
        max1 = max(max1,(a[i] - 1) / b[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        int x,y;
        if (!calc(b[i] * mod % p[i],p[i],(a[i] - b[i] * ans % p[i] + p[i]) % p[i],x,y))
            return (void)puts("-1");
        ans += mod * x;
        mod = __lcm(mod,p[i]);
    }
    if (ans < max1)
        ans += ((max1 - ans - 1) / mod + 1) * mod;
    write(ans);
    putchar('\n');
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}