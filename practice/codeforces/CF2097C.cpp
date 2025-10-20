#include<bits/extc++.h>
#define int long long
#define __lcm(x,y) ((x) * (y) / __gcd(x,y))
using namespace std;
int n,x,y,vx,vy;
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
void calc(int a,int &x,int b,int &y,int c)
{
    int tmp = __gcd(a,b);
    if (c % tmp)
    {
        x = y = -1;
        return;
    }
    a /= tmp,b /= tmp,c /= tmp;
    exgcd(a,b,x,y);
    x = (x * c % b + abs(b)) % abs(b);
    y = (c * tmp - a * x) / b;
}
void solve()
{
    cin >> n >> x >> y >> vx >> vy;
    int t1,t2,tmp = __gcd(vx,vy),p;
    vx /= tmp,vy /= tmp;
    calc(vx,t1,-n,p,-x);
    calc(vy,t2,-n,p,-y);
    if (t1 < 0 || t2 < 0)
        return cout << "-1\n",void();
    int g1 = n / __gcd(n,vx),g2 = n / __gcd(n,vy),a,b;
    tmp = __lcm(g1,g2);
    calc(g2,a,-g1,b,t1 - t2);
    if (a < 0)
        return cout << "-1\n",void();
    int tim = ((t2 + g2 * a) % tmp + tmp) % tmp;
    int tx = x + vx * tim,ty = y + vy * tim;
    if (tx % n || ty % n)
        return cout << "-1\n",void();
    tx /= n,ty /= n;
    cout << tx - 1 + ty - 1 + (tx + ty) / 2 + abs(tx - ty) / 2 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}