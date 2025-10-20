#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,d;
int a[maxn];
bool vis[maxn];
void solve()
{
    scanf("%d%d",&n,&d);
    memset(vis,0,sizeof(bool) * (n + 5));
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        int j = i,fl = 1,cnt = 0;
        int fir = -1;
        do
        {
            vis[j] = 1;
            if (!a[j])
            {
                ans = max(ans,cnt);
                if (!~fir)
                    fir = cnt;
                cnt = fl = 0;
            }
            else
                cnt++;
            j = (j + d) % n;
            if (!j)
                j = n;
        } while (!vis[j]);
        ans = max(ans,fir + cnt);
        if (fl)
            return (void)puts("-1");
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