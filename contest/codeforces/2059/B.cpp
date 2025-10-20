#include<bits/extc++.h>
using namespace std;
int n,k;
void solve()
{
    cin >> n >> k;
    vector<int>a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == n)
    {
        vector<int>b((n >> 1) + 5);
        for (int i = 1; i <= (n >> 1); i++)
        {
            if (i != a[i << 1])
            {
                cout << i << '\n';
                return;
            }
        }
        cout << (n >> 1) + 1 << '\n';
    }
    else
    {
        for (int i = 2; i <= (n - k + 2); i++)
        {
            if (a[i] != 1)
            {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
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