#include<bits/extc++.h>
using namespace std;
int n,x,sum;
void solve()
{
    cin >> n >> x;
    sum = 0;
    for (int i = 1,y; i <= n; i++)
    {
        cin >> y;
        sum += y;
    }
    puts(1.0 * sum / n == x ? "Yes" : "No");
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