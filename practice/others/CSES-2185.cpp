#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
int a[20];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 0; i < k; i++)
        scanf("%lld",a + i);
    int ans = n;
    for (int s = 0; s < 1 << k; s++)
    {
        __int128_t val = 1;
        bool fl = 1;
        for (int i = 0; i < k; i++)
        {
            if (s & (1 << i))
            {
                if ((val *= a[i]) > n)
                {
                    fl = 0;
                    break;
                }
            }
        }
        if (fl)
            ans -= (__builtin_popcountll(s) & 1 ? -1 : 1) * (n / val);
    }
    printf("%lld\n",ans);
    return 0;
}