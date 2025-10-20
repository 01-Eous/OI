#include<bits/extc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n != 1)
            cout << n * (n - 1LL) << '\n';
        else
            cout << "1\n";
    }
    return 0;
}