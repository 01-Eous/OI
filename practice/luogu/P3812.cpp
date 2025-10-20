#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int d[55];
void ins(int x)
{
    for (int i = 50; i >= 0; i--)
    {
        if (!(x & (1LL << i)))
            continue;
        if (d[i])
            x ^= d[i];
        else
        {
            d[i] = x;
            break;
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        ins(x);
    }
    int ans = 0;
    for (int i = 50; i >= 0; i--)
        if ((ans ^ d[i]) > ans)
            ans ^= d[i];
    printf("%lld",ans);
    return 0;
}