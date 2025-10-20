#include<bits/extc++.h>
using namespace std;
int a[8];
void solve()
{
    scanf("%d%d%d%d",a + 1,a + 2,a + 4,a + 5);
    int ans = 0;
    for (a[3] = -1e5; a[3] <= 1e5; a[3]++)
    {
        int cnt = 0;
        for (int i = 1; i <= 3; i++)
            if (a[i + 2] == a[i + 1] + a[i])
                cnt++;
        ans = max(ans,cnt);
    }
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