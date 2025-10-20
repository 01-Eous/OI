#include<bits/extc++.h>
using namespace std;
int n,x;
void solve()
{
    cin >> n;
    cout << "mul 999999999" << endl;
    cin >> x;
    cout << "digit" << endl;
    cin >> x;
    if (n == 81)
    {
        cout << "!" << endl;
        cin >> x;
    }
    else
    {
        cout << "add " << n - 81 << endl;
        cin >> x;
        cout << "!" << endl;
        cin >> x;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}