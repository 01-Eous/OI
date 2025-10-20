#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
void solve()
{
    scanf("%d%d",&n,&k);
    vector<int>a(n + 5,0),b(n * 2 + 5,0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; k - i > i; i++)
        ans += min(b[i],b[k - i]);
    if (k % 2 == 0)
        ans += b[k / 2] / 2;
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}