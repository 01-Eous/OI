#include<bits/extc++.h>
#define int long long
using namespace std;
int n,a,b;
void solve()
{
    cin >> n >> a >> b;
    if (a == 1)
    {
        if ((n - 1) % b == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        return ;
    }
    for (int i = 1; i <= n; i *= a)
        if (i % b == n % b)
            return cout << "Yes\n",void();
    cout << "No\n";
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