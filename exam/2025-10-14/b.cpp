#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
bool st;
int n,m;
char s[2005];
int sum[2005];
bool num[2005];
class mat
{
    public:
    int d[2][2];
    mat(int x = 0)
    {
        memset(d,0,sizeof(d));
        d[0][0] = d[1][1] = x;
    }
    friend mat operator+(const mat &x,const mat &y)
    {
        mat res(0);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                res.d[i][j] = (x.d[i][j] + y.d[i][j]) % mod;
        return res;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res(0);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res.d[i][j] = (res.d[i][j] + x.d[i][k] * y.d[k][j]) % mod;
        return res;
    }
}dp[2005][2],pw[2005],base;
bool ed;
signed main()
{
    fprintf(stderr,"%.3lfMB\n",(double)(&ed - &st) / 1024 / 1024);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> (s + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (s[i] == '1');
    base.d[0][1] = base.d[1][0] = base.d[1][1] = 1;
    pw[0] = base;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * pw[i - 1];
    dp[0][1] = mat(1);
    for (int i = 0; i < n; i++)
    {
        for (int j = min(i,m - 1); ~j; j--)
        {
            for (int k = 0; k < 2; k++)
            {
                if (k && sum[i + 1] <= j)
                    continue;
                if (k && sum[i + 1] == j + 1 && sum[i] != j + 1)
                    dp[j + 1][k] = dp[j + 1][k] + dp[j][k] * pw[n - i - 1];
                else
                    dp[j + 1][0] = dp[j + 1][0] + dp[j][k] * pw[n - i - 1];
            }
        }
    }
    cout << ((dp[m][0] + dp[m][1]) * base).d[1][0];
    return 0;
}