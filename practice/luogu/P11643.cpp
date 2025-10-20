#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int>a(n + 5),b(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n < 2)
        return void(cout << "No\n");
    int tmp;
    for (int i = 1; i < n; i++)
    {
        tmp = b[i] - a[i];
        a[i] += tmp;
        a[i + 1] += tmp;
    }
    cout << (a[n] == b[n] ? "Yes\n" : "No\n");
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