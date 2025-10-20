#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 3e5 + 5;
int n,k;
char s[maxn];
int a[maxn],b[maxn];
bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        b[i] = s[i] == 'B' || a[i] <= mid;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
        {
            int j = i;
            bool fl = 0;
            while (j <= n && b[j])
            {
                fl |= s[j] == 'B' && a[j] > mid;
                j++;
            }
            cnt += fl;
            i = j - 1;
        }
    }
    return cnt <= k;
}
void solve()
{
    scanf("%d%d%s",&n,&k,s + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    int l = 0,r = inf,ans = inf;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = min(ans,mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
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