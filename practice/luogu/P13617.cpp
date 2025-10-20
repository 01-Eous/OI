#include<bits/extc++.h>
#define int long long
#define all(x) (1LL << (x + 1)) - 1
#define __popcount __builtin_popcountll
using namespace std;
const int maxn = 5e5 + 5;
int n;
int a[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int val = 0,k = -1;
    for (int i = 2; i <= n; i++)
    {
        int x = a[i - 1] - a[i] + 1;
        if (x < 0)
        {
            cout << "-1\n";
            return;
        }
        int tmp = (1LL << x) - 1;
        int p = min(k, x),mask = all(p);
        if ((tmp & mask) != (val & mask))
        {
            cout << "-1\n";
            return;
        }
        val |= tmp,k = max(k, x);
        if (val == all(k))
            k++;
        val++;
    }
    val = val - n + 1;
	int cnt = a[1] - __popcount(val);
    if (cnt < 0)
    {
        cout << "-1\n";
        return;
    }
    while (cnt--)
        val |= 1LL << ++k;
    cout << val << '\n';
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