#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(i - (n - i + 1));
    cout << (sum >> 1) + 1 << '\n';
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