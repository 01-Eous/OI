#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int a[3005];
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= (n - 1) >> 1; j++)
        {
            if (i - j >= 1)
                res += a[i] - j - a[i - j];
            else
                res += a[i] - j + m - a[i - j + n];
        }
        for (int j = 1; j <= n >> 1; j++)
        {
            if (i + j <= n)
                res += a[i + j] - a[i] - j;
            else
                res += a[i + j - n] + m - a[i] - j;
        }
        ans = min(ans,res);
    }
    printf("%d",ans);
    return 0;
}