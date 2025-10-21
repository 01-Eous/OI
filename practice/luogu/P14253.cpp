#include<bits/extc++.h>
#define int long long   
using namespace std;
const int maxn = 1e6 + 6;
int n;
int a[maxn],sum[maxn];
unordered_map<int,int> mp;
void solve()
{
    cin >> n,mp.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        mp[sum[i]]++;
        ans = max(ans,mp[sum[i - 1]]);
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