#include<bits/extc++.h>
#define int long long
#define ull unsigned int
using namespace std;
using i3 = array<int,3>;
const int mod = 998244353;
const ull base = 1e9 + 7;
int n,d;
i3 a[105][105];
i3 operator+(const i3 &x,const i3 &y)
{return {x[0] + y[0],x[1] + y[1],x[2] + y[2]};}
i3 operator-(const i3 &x,const i3 &y)
{return {x[0] - y[0],x[1] - y[1],x[2] - y[2]};}
int calc(int x,int y,int z){return (x * x + y * y + z * z) % mod;}
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            for (int k = 0; k < d; k++)
                cin >> a[i][j][k];
        for (int j = n; j >= 1; j--)
        {
            a[i][j] = a[i][j] - a[i][j - 1];
            ans = (ans + calc(a[i][j][0],a[i][j][1],a[i][j][2])) % mod;
        }
    }
    cout << ans * binpow(n,n - 1) % mod << '\n';
    return 0;
}