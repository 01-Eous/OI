#include<bits/extc++.h>
#define int long long
using namespace std;
int n,a[105],d[35];
bool ins(int x)
{
    for (int i = 32; i >= 0; i--)
    {
        if (x & (1LL << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
    }
    return x;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1,greater<>());
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!ins(a[i]))
            ans += a[i];
    printf("%lld",ans);
    return 0;
}