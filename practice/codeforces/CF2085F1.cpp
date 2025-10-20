#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
int a[3005],l[3005],r[3005],c[3005];
int calc(int pos)
{
    fill(l + 1,l + k + 1,n + 1);
    fill(r + 1,r + k + 1,n + 1);
    for (int i = pos; i >= 1; i--)
        if (l[a[i]] == n + 1)
            l[a[i]] = pos - i;
    for (int i = pos; i <= n; i++)
        if (r[a[i]] == n + 1)
            r[a[i]] = i - pos;
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        c[i] = r[i] - l[i];
        res += l[i];
    }
    sort(c + 1,c + k + 1);
    for (int i = 1; i <= (k + 1) >> 1; i++)
        res += c[i];
    return res;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 4e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans,calc(i));
    for (int i = 1; i <= k; i++)
        ans -= abs(i - ((k + 1) >> 1));
    cout << ans << '\n';
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