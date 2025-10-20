#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
int n;
struct mat
{
    int a[5][5];
    mat(bool op = 0)
    {
        memset(a,0,sizeof a);
        if (op)
            for (int i = 1; i <= 3; i++)
                a[i][i] = 1;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                for (int k = 1; k <= 3; k++)
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
        return res;
    }
}base,ori;
mat binpow(mat x,int y)
{
    mat res(1);
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
    }
    return res;
}
void solve()
{
    scanf("%lld",&n);
    mat ans = binpow(base,n) * ori;
    printf("%lld\n",(ans.a[1][1] + ans.a[2][1] + ans.a[3][1]) % mod);
}
signed main()
{
    base.a[1][1] = base.a[1][2] = base.a[1][3] =
    base.a[2][1] = base.a[3][2] = ori.a[1][1] = 1;
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}