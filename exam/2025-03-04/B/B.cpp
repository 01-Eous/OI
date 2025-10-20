// 死去的几何还在追我
#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
struct long_int
{
    int len;
    char d[105];
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
    void inf()
    {
        len = 100;
        fill(d + 1,d + len + 1,9);
    }
    void read()
    {
        char ch = getchar() ;
        while (!isdigit(ch))ch = getchar();
        len = 0;
        while (isdigit(ch)){d[++len] = ch - '0'; ch = getchar();}
        reverse(d + 1,d + len + 1);
    }
    friend bool operator==(const long_int &x,const long_int &y)
    {
        if (x.len != y.len)
            return 0;
        for (int i = x.len; i; i--)
            if (x.d[i] != y.d[i])
                return 0;
        return 1;
    }
    friend bool operator<(const long_int &x,const long_int &y)
    {
        if (x.len != y.len)
            return x.len < y.len;
        for (int i = x.len; i; i--)
            if (x.d[i] != y.d[i])
                return x.d[i] < y.d[i];
        return 0;
    }
}x[maxn << 1],y[maxn << 1],minx,miny;
signed main()
{
    scanf("%d",&n);
    minx.inf(),miny.inf();
    for (int i = 1; i <= n; i++)
    {
        x[i].read(),y[i].read();
        minx = min(minx,x[i]);
        x[i + n] = x[i];
        y[i + n] = y[i];
    }
    int st = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == minx)
        {
            if (y[i] < miny)
            {
                miny = y[i];
                st = i;
            }
        }
    }
    if (st == 1)
        x[0] = x[n],y[0] = y[n];
    bool fl = 0,lst = 0;
    int cnt = 0;
    // 对于竖线，有 fl = 1 时右为外
    // 对于横线，有 fl = 1 时上为外
    // 对于竖线，lst = 1 表示它向上
    // 对于横线，lst = 1 表示它向右
    // 对于最左下的点，链接它的两条边一定有左下为外
    for (int i = st; i < st + n; i++)
    {
        bool cur;// 当前朝向
        if (x[i] == x[i + 1])
            cur = y[i] < y[i + 1];
        else
            cur = x[i] < x[i + 1];
        cnt += cur == fl;
        if (lst)
            fl = fl != cur;
        else
            fl = fl == cur;  
        lst = cur;
    }
    cout << cnt;
    return 0;
}