#include<bits/extc++.h>
using namespace std;
int n,m;
char a[1005];
void solve()
{
    cin >> n >> m;
    int lst = -114514,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == '1')
        {
            if (lst < i - m + 1)
                ans++;
            lst = i;
        }
    }
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