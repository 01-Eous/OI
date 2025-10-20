#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
int a[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    scanf("%lld",&m);
    int ans = 0x7fffffff;
    for (int i = 30; i >= 0; i--)
    {
        ans ^= 1 << i;
        int tmp = 0;
        bool fl = 0;
        for (int j = 1; j <= n && !fl; j++)
        {
            for (int k = 0; k <= 30; k++)
            {
                if ((ans | (a[j] << k)) == ans)
                {
                    tmp += k;
                    break;
                }
                if (k == 30)
                    fl = 1;
            }
            if (tmp > m)
                fl = 1;
        }
        if (fl)
            ans ^= 1 << i;
    }
    printf("%lld",ans);
    return 0;
}