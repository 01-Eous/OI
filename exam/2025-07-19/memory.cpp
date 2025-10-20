// 能否通过全局 -1 然后单点 +x 的操作使得所有数相等？
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m,k,x;
int a[maxn],b[maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void solve()
{
    n = read(),k = read(),x = read();
    m = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] = read(); i != k)
            b[++m] = a[i];
    stable_sort(b + 1,b + m + 1);
    int dec = 0;
    for (int i = 1; i < m; i++)
    {
        if ((b[i + 1] - b[i]) % (x + 1))
            return (void)puts("sorry");
        dec += (b[i + 1] - b[i]) / (x + 1) * i;
    }
    printf("%lld ",b[m]);
    b[m] -= dec,a[k] -= dec;
    a[k] += b[m] * x;
    printf("%lld\n",a[k]);
}
signed main()
{
    freopen("memory.in","r",stdin);
    freopen("memory.out","w",stdout);
    read();
    int t = read();
    while (t--)
        solve();
    fprintf(stderr,"%.3lf\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}