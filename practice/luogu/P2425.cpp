#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,idx;
int dig[40];
bool chk(int x)
{
    idx = 0;
    int tmp = n;
    while (tmp)
    {
        dig[++idx] = tmp % x;
        tmp /= x;
    }
    for (int i = 1,j = idx; i < j; i++,j--)
        if (dig[i] != dig[j])
            return 0;
    return 1;
}
void solve()
{
    cin >> n;
    if (n == 1)
        return cout << "2\n",void();
    for (int i = 2; i * i < n; i++)
        if (chk(i))
            return cout << i << '\n',void();
    int ans = inf;
    for (int i = 1; i * i < n; i++)
        if (n % i == 0)
            ans = min(ans,n / i - 1);
    cout << ans << '\n';
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