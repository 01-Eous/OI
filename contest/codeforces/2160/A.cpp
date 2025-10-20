#include<bits/extc++.h>
using namespace std;
int n;
map<int,bool> apr;
void solve()
{
    cin >> n;
    apr.clear();
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        apr[x] = 1;
    }
    int ans = 0;
    while (apr[ans])
        ans++;
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