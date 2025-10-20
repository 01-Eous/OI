#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 4e5 + 5;
int n;
int b[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n << 1; i++)
        cin >> b[i];
    sort(b + 1,b + (n << 1) + 1);
    int sum1 = 0,sum2 = 0;
    for (int i = 1; i < n; i++)
        sum1 += b[i];
    for (int i = n; i <= (n << 1); i++)
        sum2 += b[i];
    cout << b[n] << ' ' << sum2 - sum1 << ' ';
    for (int i = 1; i <= n; i++)
    {
        cout << b[i + n];
        if (i == n)
            cout << '\n';
        else
            cout << ' ' << b[i] << ' ';
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