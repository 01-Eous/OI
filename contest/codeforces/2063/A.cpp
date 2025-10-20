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
        int l,r;
        cin >> l >> r;
        if (l == 1 && (r == 2 || r == 1))
            cout << 1 << endl;
        else
            cout << r - l << endl;
    }
    return 0;
}