#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define chkmin(x,y) x = min(x,y)
using namespace std;
const int maxn = 2e5 + 5;
int n;
int mp[maxn << 1];
int a[maxn],sum[maxn];
void solve()
{
    cin >> n;
    char ch;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        a[i] = ch == 'a' ? 1 : -1;
        sum[i] = sum[i - 1] + a[i];
    }
    memset(mp,0x3f,sizeof(int) * ((n << 1) + 5));
    int suf = 0,ans = inf;
    for (int i = n; i >= 0; i--)
    {
        chkmin(mp[n + suf],i);
        suf += a[i];
        chkmin(ans,mp[n - sum[i]] - i);
    }
    if (ans >= n)
        cout << "-1\n";
    else
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