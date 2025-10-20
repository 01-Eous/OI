#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n;
int siz[maxn];
pii a[maxn],ans[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        siz[i] = 1;
    }
    sort(a + 1,a + n + 1);
    int dis = 0,idx = 0;
    for (int i = n; i > 1; i--)
    {
        int tmp = a[i].first - n + (siz[i] << 1);
        int pos = lower_bound(a + 1,a + n + 1,pii{tmp,0}) - a;
        if (a[pos].first != tmp)
            return cout << "-1",0;
        ans[++idx] = {a[i].second,a[pos].second};
        siz[pos] += siz[i],dis += siz[i];
    }
    if (dis != a[1].first)
        return cout << "-1",0;
    for (int i = 1; i <= idx; i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}