#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,m;
pii a[maxn];
bool cmp(const pii &x,const pii &y){return x.first - x.second < y.first - y.second;}
int pos(const pii &cir,int x)
{return floor(sqrt(sq(cir.second) - sq(cir.first - x)));}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    map<int,int> mp;
    for (int i = 1; i <= n; i++)
        for (int x = a[i].first - a[i].second; x <= a[i].first + a[i].second; x++)
            mp[x] = max(mp[x],pos(a[i],x));
    int ans = 0;
    for (auto [x,y] : mp)
        ans += y << 1 | 1;
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