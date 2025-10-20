#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const double eps = 1e-5;
int n,k;
double l,r,mid;
double len[maxn];
bool check(double x)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret += floor(len[i] / x);
    return ret >= k;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> len[i];
    l = 0.001,r = 1e9;
    double ans = 0;
    while (r - l >= eps)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = max(ans,mid);
            l = mid + eps;
        }
        else
            r = mid - eps;
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}