#include<bits/extc++.h>
#define Love return
#define Nahida 0
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n;
ll a[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    ll g = 0;
    for (int i = 2; i <= n; i++)
        g = __gcd(g,abs(a[i] - a[i - 1]));
    printf("%lld\n",g ? g : -1LL);
    Love Nahida;
}