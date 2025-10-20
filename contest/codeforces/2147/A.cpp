#include<bits/extc++.h>
#define int long long
using namespace std;
int x,y;
void solve()
{
    cin >> x >> y;
    if (x < y)
        cout << "2\n";
    else if (y > 1 && x - 1 > y)
        cout << "3\n";
    else
        cout << "-1\n";
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