#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,x;
int lowbit(int x){return x & -x;}
signed main()
{
    scanf("%lld",&n);
    int ans = 0;
    while (n--)
    {
        scanf("%lld",&x);
        ans += x != lowbit(x);
    }
    printf("%lld",ans);
    return 0;
}