#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
void solve()
{
    cin >> n;
    if (!(n & 1))
        return cout << "-1\n",void();
    else if (n == 3)
        return cout << "3 2 1\n",void();
    cout << "1 " << n << ' ';
    for (int i = 2; i < n; i++)
        cout << i << " \n"[i == n - 1];
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