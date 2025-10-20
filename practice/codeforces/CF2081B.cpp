#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0,l = 0,r = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i + 1])
            continue;
        cnt++;
        if (!l)
            l = i;
        r = i + 1;
    }
    if ((cnt & 1) || (l && a[r] - a[l] < r - l))
        cout << (cnt >> 1) + 1 << '\n';
    else
        cout << (cnt >> 1) << '\n';
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