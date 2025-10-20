#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e4 + 5;
int n,m;
int l,r,mid;
int a[maxn],dp[maxn];
bool chk(int mid)
{
    for (int i = 1,j = 0; i <= n; i++)
    {
        while (a[i] - a[j] >= mid)
            j++;
        if (!j)
            dp[i] = 0;
        else
            dp[i] = dp[--j] + 1;
    }
    return n - dp[n] <= m;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[++n] = r;
    l = 1;
    int ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}