#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    if (__popcount(n) == 1)
        cout << "-1\n";
    else if (n == (1 << __popcount(n)) - 1)
        cout << "-1\n";
    else
    {
        int ans = n;
        for (int i = 0; 1 << i < n; i++)
        {
            if (!(n & (1 << i)))
            {
                ans -= 1 << i;
                break;
            }
        }
        cout << ans << '\n';
    }
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