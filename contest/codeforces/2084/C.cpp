#include<bits/extc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 10;
int n;
pii a[maxn];
vector<pii> ans;
map<pii,int> mp;
void swp(int i)
{
    pii tmp = a[i];
    swap(tmp.first,tmp.second);
    if (!mp.count(tmp))
        return cout << "-1\n",void();
    if (mp[tmp] != n - i + 1)
    {
        
        int tpos = mp[tmp];
        ans.push_back({tpos,n - i + 1});
        mp[a[n - i + 1]] = mp[tmp],mp[tmp] = n - i + 1;
        swap(a[tpos],a[n - i + 1]);
    }
}
void solve()
{
    mp.clear(),ans.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
        mp[a[i]] = i;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first == a[i].second)
        {
            if (!(n & 1) || pos)
                return ` << "-1\n",void();
            pos = i;
        }
    }
    if (pos && pos <= n >> 1)
        for (int i = n; i > n >> 1; i--)
            swp(i);
    else
        for (int i = 1; i <= n >> 1; i++)
            swp(i);
    if ((n & 1) && a[(n + 1) >> 1].first != a[(n + 1) >> 1].second)
        return cout << "-1\n",void();
    cout << ans.size() << '\n';
    for (auto [x,y] : ans)
        cout << x << ' ' << y << '\n';
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