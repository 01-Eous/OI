#include<bits/extc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n;
int a[maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
bool chk(int x,int y)
{
    bool f1 = min(x - 1,y - x - 1) << 1 >= abs((n - y) - (y - 1));
    bool f2 = min(n - y,y - x - 1) << 1 >= abs((n - x) - (x - 1));
    return f1 || f2;
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int ans = 0,max1 = a[(n + 1) >> 1];
    for (int i = 2,j = (n + 1) >> 1; i <= (n + 1) >> 1; i++)
    {
        if (i == (n + 1) >> 1)
            ans = max(ans,a[i]);
        while (chk(i,j + 1))
            max1 = max(max1,a[++j]);
        ans = max(ans,min(a[i],max1));
    }
    printf("%d\n",ans);
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}