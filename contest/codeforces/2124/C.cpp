#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 6e5 + 5;
int n;
int a[maxn];
int __lcm(int x,int y){return x * y / __gcd(x,y);}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    int ans = 1;
    for (int i = n - 1; i; i--)
        ans = __lcm(ans,a[i] / __gcd(a[i],a[i + 1]));
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}