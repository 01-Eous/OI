#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],max1[maxn],min1[maxn];
void solve()
{
    cin >> n;
    int sum = 0,ans = n - 2 + (n & 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i],sum += (i & 1 ? 1 : -1) * a[i];
    min1[1] = (a[1] << 1) + 1;
    for (int i = 2; i <= n; i++)
    {
        if (i & 1)
            min1[i] = min(min1[i - 2],(a[i] << 1) + i);
        else
            max1[i] = max(max1[i - 2],(a[i] << 1) - i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            ans = max(ans,max1[i - 1] - (a[i] << 1) + i);
        else
            ans = max(ans,(a[i] << 1) - min1[i - 1] + i);
    }
    cout << ans + sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}