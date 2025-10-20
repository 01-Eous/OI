#include<bits/extc++.h>
using namespace std;
int n;
int a,b,c,ans;
random_device seed;
void solve()
{
    cin >> n;
    if (n == -1)
        exit(0);
    a = 1,b = 2,c = 3;
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    cin >> ans;
    while (ans)
    {
        int tmp = rand() % 3;
        if (tmp == 0)
            a = ans;
        else if (tmp == 1)
            b = ans;
        else
            c = ans;
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        cin >> ans;
    }
    cout << "! " << a << ' ' << b << ' ' << c << endl;
}
signed main()
{
    srand(time(0) * seed());
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}