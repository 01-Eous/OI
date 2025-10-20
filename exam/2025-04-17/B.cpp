#include<bits/extc++.h>
#define int long long
#define __lg(__n) (63 ^ __builtin_clzll(__n))
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 2e6 + 5;
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
signed main()
{
    n = read();
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = __lg(--n) + 1;
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
        st[0][i] = abs(a[i + 1] - a[i]);
    fprintf(stderr,"b1:%.2lf\n",(double)clock() / CLOCKS_PER_SEC * 1000);
    #pragma GCC unroll 8
    for (int i = 1; i <= m; i++)
        #pragma GCC unroll 8
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[i][j] = __gcd(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]);
    fprintf(stderr,"b2:%.2lf\n",(double)clock() / CLOCKS_PER_SEC * 1000);
    int ans = 0;
    #pragma GCC unroll 8
    for (int i = 1,j = 1; i <= n; i++)
    {
        j = max(i,j);
        while (j <= n && que(i,j) != 1)
            j++;
        ans = max(ans,j - i + 1);
    }
    printf("%lld\n",ans);
    fprintf(stderr,"b3:%.2lf\n",(double)clock() / CLOCKS_PER_SEC * 1000);
    return 0;
}