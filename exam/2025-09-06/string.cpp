#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],b[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%1d",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%1d",b + i);
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (a[i - 1] != b[i - 1] && a[i] != b[i] && a[i] != a[i - 1])
            ans++,swap(a[i],a[i - 1]);
    for (int i = 1; i <= n; i++)
        ans += a[i] != b[i];
    printf("%d",ans);
    return 0;
}