#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    a[n + 1] = 0;
    int idx = 0,h = 0;
    for (int i = n; i >= 1; i--)
    {
        if (!h && a[i] == a[i - 1])
        {
            h = a[i];
            i--;
        }
        else
            b[++idx] = a[i];
    }
    if (!h)
    {
        cout << "-1\n";
        return;
    }
    sort(b + 1,b + idx + 1);
    int _min = 1e9,x,y;
    for (int i = 1; i < idx; i++)
    {
        if (abs(b[i] - b[i + 1]) < _min)
        {
            x = b[i],y = b[i + 1];
            _min = abs(b[i] - b[i + 1]);
        }
    }
    if (_min < (h << 1))
        cout << h << " " << x << " " << h << " " << y << "\n";
    else
        cout << "-1\n";
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