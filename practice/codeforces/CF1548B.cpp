#include<bits/extc++.h>
#define int long long
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 2e5 + 5;
char buf[1 << 23],*p1 = buf,*p2 = buf;
int n,m;
int a[maxn],st[25][maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
int que(int l,int r)
{
    int k = __lg(r - l + 1);
    return __gcd(st[k][l],st[k][r - (1 << k) + 1]);
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = __lg(--n) + 1;
    for (int i = 1; i <= n; i++)
        st[0][i] = abs(a[i + 1] - a[i]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[i][j] = __gcd(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]);
    int ans = 1;
    for (int i = 1,j = 1; i <= n; i++)
    {
        j = max(i,j);
        while (j <= n && que(i,j) != 1)
            j++;
        ans = max(ans,j - i + 1);
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}