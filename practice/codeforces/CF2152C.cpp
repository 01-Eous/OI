#include<bits/extc++.h>
using namespace std;
const int maxn = 2.5e5 + 5;
int n,q;
int a[maxn];
int sum[maxn][2],pre[maxn];
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i][0] = sum[i - 1][0] + (!a[i]);
        sum[i][1] = sum[i - 1][1] + a[i];
        pre[i] = pre[i - 1] + (a[i] != a[i - 1]);
    }
    int l,r;
    while (q--)
    {
        cin >> l >> r;
        int cnt0 = sum[r][0] - sum[l - 1][0];
        int cnt1 = sum[r][1] - sum[l - 1][1];
        if (cnt0 % 3 || cnt1 % 3)
        {
            cout << "-1\n";
            continue;
        }
        int ans = (r - l + 1) / 3;
        if (pre[r] - pre[l] == r - l)
            ans++;
        cout << ans << '\n';
    }
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