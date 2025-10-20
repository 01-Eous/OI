#include<bits/extc++.h>
using namespace std;
int n,m;
signed main()
{
    scanf("%d%d",&n,&m);
    if (m == 0)
    {
        puts("0");
        for (int i = 1; i <= n; i++)
            printf("0 ");
        return;
    }
    int tmp = (n + 1) >> 1;
    printf("%lld\n",1LL * tmp * (n - tmp + 1));
    for (int i = 1; i < m; i++)
        printf("1 ");
    n -= m;
    for (int i = 1; i <= n - (n >> 1); i++)
        printf("0 ");
    printf("1 ");
    for (int i = 1; i <= (n >> 1); i++)
        printf("0 ");
    return 0;
}