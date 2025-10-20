#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b;
void solve()
{
    cin >> a >> b;
    if (a != b)
        cout << (1ll << 48) - max(a,b) << '\n';
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