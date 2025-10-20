#include<bits/extc++.h>
using namespace std;
struct long_int
{
    int len;
    short d[105];
    long_int(int x = 0)
    {
        memset(d,0,sizeof d);
        len = 0;
        while (x)
        {
            d[++len] = x % 10;
            x /= 10;
        }
    }
    void read()
    {
        char ch = getchar();
        while (!isdigit(ch))ch = getchar();
        len = 0;
        while (isdigit(ch)){d[++len] = ch - '0'; ch = getchar();}
        reverse(d + 1,d + len + 1);
    }
    void write()
    {
        for (int i = len; i >= 1; i--)
            printf("%d",d[i]);
    }
    friend long_int operator+(const long_int &x,const long_int &y)
    {
        long_int ret;
        ret.len = max(x.len,y.len);
        short f = 0;
        for (int i = 1; i <= ret.len; i++)
        {
            ret.d[i] = x.d[i] + y.d[i] + f;
            if (ret.d[i] >= 10)
            {
                f = 1;
                ret.d[i] -= 10;
            }
            else
                f = 0;
        }
        if (f)
            ret.d[++ret.len] = f;
        return ret;
    }
    friend long_int operator-(const long_int &x,const long_int &y)
    {
        long_int ret;
        ret.len = max(x.len,y.len);
        short f = 0;
        for (int i = 1; i <= ret.len; i++)
        {
            ret.d[i] = x.d[i] - y.d[i] - f;
            if (ret.d[i] < 0)
            {
                f = 1;
                ret.d[i] += 10;
            }
            else
                f = 0;
        }
        while (!ret.d[ret.len])
            ret.len--;
        return ret;
    }
    friend long_int operator*(const long_int &x,const long_int &y)
    {
        long_int ret;
        ret.len = x.len + y.len - 1;
        for (int i = 1; i <= x.len; i++)
            for (int j = 1; j <= y.len; j++)
                ret.d[i + j - 1] += x.d[i] * y.d[j];
        for (int i = 1; i <= ret.len; i++)
        {
            ret.d[i + 1] += ret.d[i] / 10;
            ret.d[i] %= 10;
        }
        if (ret.d[ret.len + 1])
            ret.len ++;
        return ret;
    }
}dp[55][55];
void calc()
{
    for (int i = 0; i <= 50; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= 50; i++)
        for (int j = 1; j <= 50; j++)
            for (int k = 1; k <= i; k++)
                dp[i][j] = dp[i][j] + dp[i - k][j] * dp[k - 1][j - 1];
}
signed main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    calc();
    int t = 0,n,k;
    scanf("%d%d",&n,&k);
    while (n || k)
    {
        if (t)
            puts("\n");
        printf("Case %d: ",++t);
        (dp[n][k] - dp[n][k - 1]).write();
        scanf("%d%d",&n,&k);
    }
    return 0;
}