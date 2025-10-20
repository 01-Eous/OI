#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    map<int,bool>a,b;
    int cnt1 = 0,cnt2 = 0,x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (!a[x])
            cnt1++;
        a[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (!b[x])
            cnt2++;
        b[x] = 1;
    }
    if (cnt1 >= 3 || cnt2 >= 3)
        cout << "YES\n";
    else if (cnt1 == 2)
    {
        if (cnt2 >= 2)  
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else if (cnt2 == 2)
    {
        if (cnt1 >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
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