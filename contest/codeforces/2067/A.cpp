#include<bits/extc++.h>
using namespace std;
int x,y;
void solve()
{
    cin >> x >> y;
    if (y - x == 1)
        cout << "YES\n";
    else if (x > y && (x - y + 1) % 9 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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