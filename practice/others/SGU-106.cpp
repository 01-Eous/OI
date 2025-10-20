#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,c,lx,rx,ly,ry;
void exgcd(int &x,int &y,int a,int b)
{
    if (!b)
    {
        x = 1,y = 0;
        return;
    }
    exgcd(x,y,b,a % b);
    int tmp = x;
    x = y;
    y = tmp - a / b * y;
}
signed main()
{
    cin >> a >> b >> c >> lx >> rx >> ly >> ry;
    if (!a && !b)
    {
        if (c)
            return cout << "0",0;
        cout << (rx - lx + 1) * (ry - ly + 1);
        return 0;
    }
    else if (!a)
    {
        if (c % b)
            return cout << "0",0;
        int tmp = c / b;
        cout << (ly <= tmp && tmp <= ry);
        return 0;
    }
    else if (!b)
    {
        if (c % a)
            return cout << "0",0;
        int tmp = c / a;
        cout << (lx <= tmp && tmp <= rx);
        return 0;
    }
    int tmp = gcd(a,b);
    if (c % tmp)
        return cout << "0",0;
    a /= tmp,b /= tmp,c /= -tmp;
    // 变为 ax + by = c
    int x0,y0;
    exgcd(x0,y0,a,b);
    x0 *= c,y0 *= c;
    double tmpl,tmpr;
    tmpl = (double)(lx - x0) / b,tmpr = (double)(rx - x0) / b;
    if (tmpl > tmpr)
        swap(tmpl,tmpr);
    int l1 = ceil(tmpl),r1 = floor(tmpr);
    tmpl = (double)(ly - y0) / -a,tmpr = (double)(ry - y0) / -a;
    if (tmpl > tmpr)
        swap(tmpl,tmpr);
    int l2 = ceil(tmpl),r2 = floor(tmpr);
    int l = max(l1,l2),r = min(r1,r2);
    cout << max(0LL,r - l + 1);
    return 0;
}