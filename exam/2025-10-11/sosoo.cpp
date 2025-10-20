#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,a,b;
inline int binpow(int x,int y)
{
    int res = 1;
    for (; y ; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
inline int sum(int n){return binpow(2,n + 1) - 2;}
inline int calc(int x,int y)
{return (x * binpow(2,y - x + 1) - (y % mod) + sum(y - x) + mod) % mod;}
void solve()
{
    cin >> n >> a >> b;
    int s = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if ((b << 1) - i > a + i && (a << 1) - i > b + i)
        {
            s = i;
            break;
        }
        int ta = max((b << 1) - i,a + i);
        int tb = max((a << 1) - i,b + i);
        a = ta,b = tb;
    }
    a %= mod,b %= mod;
    if ((n - s + 1) & 1)
        swap(a,b);
    int tmp = calc(s,n);
    a = (a * binpow(2,n - s + 1) % mod - tmp + mod) % mod;
    b = (b * binpow(2,n - s + 1) % mod - tmp + mod) % mod;
    cout << a << ' ' << b << '\n';
}
signed main()
{
    freopen("sosoo.in","r",stdin);
    freopen("sosoo.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}