#include<bits/extc++.h>
#define int long long
using namespace std;
const int q1 = 0x2aaaaaaa,q2 = 0x15555555;
int a1,a2,x,y,m;
void solve()
{
    cout << q1 << endl;
    cin >> a1;
    a1 -= q1 * 2;
    cout << q2 << endl;
    cin >> a2;
    a2 -= q2 * 2;
    x = y = 0;
    for (int i = 0; i < 30; i++)
    {
        int tmp = i & 1 ? a2 : a1;
        if (tmp & (1 << i))
            x |= (1 << i);
        else if (tmp & (1 << (i + 1)))
        {
            x |= (1 << i);
            y |= (1 << i);
        }
    }
    cout << '!' << endl;
    cin >> m;
    cout << (m | x) + (m | y) << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
// 5726623061
// 2863311532