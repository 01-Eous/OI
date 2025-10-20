#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
int a[maxn],b[maxn];
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    m = (m & 1) | 2;
    while (m--)
    {
        memset(b,0,sizeof(int) * (n + 5));
        for (int i = 1; i <= n; i++)
            a[i] = ++b[a[i]];
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c",a[i]," \n"[i == n]);
    return 0;
}