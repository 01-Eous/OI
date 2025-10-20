#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int>a(n + 5);
    for (int i = 2; i < n; i++)
        cin >> a[i];
    for (int i = 3; i < n - 1; i++)
    {
        if (!a[i] && a[i - 1] && a[i + 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}