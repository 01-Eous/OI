#include<bits/extc++.h>
using namespace std;
using ld = double;
using ll = long long;
using pii = pair<int,int>;
const ll mod = 1e9 + 7;
const ld lg = log(3) / log(2);
ld max1,res;
int n,pw2,pw3;
int l,r,mid,res2,res3;
int a[1005][1005];
int cntr[5][1005][1005],cntc[5][1005][1005],cntd[5][1005][1005],cntu[5][1005][1005];
bool chk1(int i,int j,int d)
{return cntr[0][i][j + d - 1] - cntr[0][i][j - d] + cntc[0][i + d - 1][j] - cntc[0][i - d][j] == 0;}
bool chk2(int i,int j,int d)
{return cntd[0][i + d - 1][j + d - 1] - cntd[0][i - d][j - d] + cntu[0][i + d - 1][j - d + 1] - cntu[0][i - d][j + d] == 0;}
pii calc1(int i,int j,int d)
{
    return {
        cntr[2][i][j + d - 1] - cntr[2][i][j - d] + cntc[2][i + d - 1][j] - cntc[2][i - d][j] - (a[i][j] == 2),
        cntr[3][i][j + d - 1] - cntr[3][i][j - d] + cntc[3][i + d - 1][j] - cntc[3][i - d][j] - (a[i][j] == 3),
    };
}
pii calc2(int i,int j,int d)
{
    return {
        cntd[2][i + d - 1][j + d - 1] - cntd[2][i - d][j - d] + cntu[2][i + d - 1][j - d + 1] - cntu[2][i - d][j + d] - (a[i][j] == 2),
        cntd[3][i + d - 1][j + d - 1] - cntd[3][i - d][j - d] + cntu[3][i + d - 1][j - d + 1] - cntu[3][i - d][j + d] - (a[i][j] == 3),
    };
}
template<typename checker,typename calculator>
void bin(int i,int j,checker chk,calculator calc)
{
    l = 1,r = min({i,j,n - i + 1,n - j + 1});
    res2 = res3 = res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(i,j,mid))
        {
            pii tmp = calc(i,j,mid);
            res2 = tmp.first;
            res3 = tmp.second;
            res = res2 + res3 * lg;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (res > max1)
        max1 = res,pw2 = res2,pw3 = res3;
}
ll binpow(ll x,int y)
{
    ll res = 1;
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
    scanf("%d",&n);
    bool fl = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d",&a[i][j]);
            fl |= a[i][j];
            for (int k = 0; k <= 3; k++)
            {
                cntr[k][i][j] = cntr[k][i][j - 1] + (a[i][j] == k);
                cntc[k][i][j] = cntc[k][i - 1][j] + (a[i][j] == k);
                cntd[k][i][j] = cntd[k][i - 1][j - 1] + (a[i][j] == k);
                cntu[k][i][j] = cntu[k][i - 1][j + 1] + (a[i][j] == k);
            }
        }
    }
    if (!fl)
        return puts("0"),0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
            {
                bin(i,j,chk1,calc1);
                bin(i,j,chk2,calc2);
            }
        }
    }
    printf("%lld\n",binpow(2,pw2) * binpow(3,pw3) % mod);
    return 0;
}