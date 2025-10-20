#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,m;
struct mat
{
    int d[20][20];
    mat(bool op = 0)
    {
        memset(d,0,sizeof d);
        if (!op)
            return;
        for (int i = 1; i <= m; i++)
            d[i][i] = 1;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= m; k++)
                    res.d[i][j] = (res.d[i][j] + x.d[i][k] * y.d[k][j]) % mod;
        return res;
    }
}ori,base;
mat binpow(mat x,int y)
{
    mat res(1);
    while (y)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}
signed main()
{
    cin >> n >> m;
    m++;
    for (int i = 1; i <= m; i++)
        ori.d[1][i] = i + 1;
    for (int i = 2; i <= m; i++)
        base.d[i][i - 1] = 1;
    base.d[1][m] = base.d[m][m] = 1;
    mat ans = ori * binpow(base,n - 1);
    cout << ans.d[1][1];
    return 0;
}