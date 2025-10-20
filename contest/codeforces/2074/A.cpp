#include<bits/extc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int l,r,d,u;
        cin >> l >> r >> d >> u;
        cout << (l == r && r == d && d == u ? "YES\n" : "NO\n");
    }
    return 0;
}