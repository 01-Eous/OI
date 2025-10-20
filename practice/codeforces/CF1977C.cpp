#include<bits/extc++.h>
#define int long long
#define __lcm(x,y) ((x) * (y) / __gcd(x,y))
using namespace std;
const int maxn = 1e5 + 5;
int n,_max;
int a[maxn];
map<int,int>cnt;
int calc(int x)
{
    vector<int>v;
    for (int i = 1; i <= n; i++)
        if (x % a[i] == 0)
            v.push_back(a[i]);
    int lcm = 1;
    for (int i : v)
    {
        lcm = __lcm(lcm,i);
        if (lcm > x)
            return 0;
    }
    return lcm == x ? v.size() : 0;
}
void solve()
{
    cin >> n;
    cnt.clear(),_max = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        _max = max(_max,a[i]);
    }
    int lcm = 1;
    for (int i = 1; i <= n; i++)
    {
        lcm = __lcm(lcm,a[i]);
        if (lcm > _max)
        {
            cout << n << '\n';
            return;
        }
    }
    int ans = 0;
    for (int i = 1; i * i <= _max; i++)
    {
        if (_max % i)
            continue;
        if (cnt.count(i) == 0)
            ans = max(ans,calc(i));
        if (cnt.count(lcm / i) == 0)
            ans = max(ans,calc(lcm / i));
    }
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