#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;
int n;
int l[maxn],r[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d",l + i,r + i);
    sort(l + 1,l + n + 1,greater<>());
    sort(r + 1,r + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n && (l[i] > r[i]); i++)
        ans += (ll)(n - (i << 1) + 1) * (l[i] - r[i]);
    printf("%lld",ans);
    return 0;
}