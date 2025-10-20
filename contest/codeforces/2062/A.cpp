#include<bits/extc++.h>
using namespace std;
string s;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int ans = 0;
        for (auto i : s)
            ans += (i == '1');
        cout << ans << "\n";
    }
    return 0;
}