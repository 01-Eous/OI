#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 21; ~j; j--)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (a[i] >> j) & 1;
        if (cnt < 2)
            continue;
        for (int i = 1; i <= n; i++)
            if (!((a[i] >> j) & 1))
                a[i] = 0;
    }
    sort(a + 1,a + n + 1,greater<>());
    cout << (a[1] & a[2]) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case #" << i << ": ",solve();
    return 0;
}