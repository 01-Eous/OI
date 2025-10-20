#include<bits/extc++.h>
using namespace std;
int x,n,m;
int calc(int x,int n,double (*op)(double))
{
    while (n--)
    {
        int tmp = op(x / 2.0);
        if (tmp == x)
            break;
        x = tmp;
    }
    return x;
}
void solve()
{
    cin >> x >> n >> m;
    cout << calc(calc(x,m,ceil),n,floor) << ' ' << calc(calc(x,n,floor),m,ceil) << '\n';
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