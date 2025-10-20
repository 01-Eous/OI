#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int a[maxn],sum[maxn];
void solve()
{
    cin >> n >> k;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        a[i] = x <= k ? 1 : -1;
    }
    int x = inf,y = inf;
    map<int,int> mp;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] >= 0)
        {
            if (!x)
                x = i;
            if (mp.find(sum[i]) == mp.end())
                mp[sum[i]] = i;
            else
                mp[sum[i]] = min(mp[sum[i]],i);
            auto it = --mp.upper_bound(sum[i]);
            if (it->second < i)
                return cout << "YES\n",void();
        }
    }
    reverse(a + 1,a + n + 1);
    fill(sum + 1,sum + n + 1,0);
    mp.clear();
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] >= 0)
        {
            if (!y)
                y = i;
            if (mp.find(sum[i]) == mp.end())
                mp[sum[i]] = i;
            else
                mp[sum[i]] = min(mp[sum[i]],i);
            auto it = --mp.upper_bound(sum[i]);
            if (it->second < i)
                return cout << "YES\n",void();
        }
    }
    if (x + y < n)
        cout << "YES\n";
    else
        cout << "NO\n";
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