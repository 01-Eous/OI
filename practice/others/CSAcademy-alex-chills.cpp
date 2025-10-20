#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,ql,qr;
int a[maxn];
signed main()
{
    scanf("%d%d%d",&n,&ql,&qr);
    int ans = 0,max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        a[n + 1] ^= a[i];
    }
    n++;
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
        max1 = max(max1,a[i]);
    }
    if (qr - ql >= n)
        return printf("%d\n",max1),0;
    ql %= n,qr %= n;
    if (ql == 0)
        ql = n;
    if (qr == 0)
        qr = n;
    if (qr < ql)
        qr += n;
    for (int i = ql; i <= qr; i++)
        ans = max(ans,a[i]);
    printf("%d",ans);
    return 0;
}