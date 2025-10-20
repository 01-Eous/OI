#include<bits/extc++.h>
#define int long long
using namespace std;
using ld = long double;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[maxn],b[maxn];
vector<pii> vec;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            ans += b[i];
        else
            vec.push_back({a[i],b[i]});
    }
    ld max1 = ans;
    int pos = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        auto [x,y] = vec[i];
        ld tmp = (ans + y) / (ld)x;
        if (max1 < tmp)
            max1 = tmp,pos = i;
    }
    if (~pos)
        ans = (ans + vec[pos].second) % mod;
    for (int i = 0; i < vec.size(); i++)
        if (i != pos)
            ans = (ans * vec[i].first) % mod;
    cout << ans;
    return 0;
}