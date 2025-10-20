#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,idx;
int a[maxn],ans[maxn];
void solve()
{
    cin >> n,idx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int p = i - (a[i] - a[i - 1]);
        if (!p)
            ans[i] = ++idx;
        else
            ans[i] = ans[p];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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