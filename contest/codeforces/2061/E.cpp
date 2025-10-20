#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define U 0x3fffffffffffffff
using namespace std;
int n,m,k,sum;
void solve()
{
    cin >> n >> m >> k;
    vector<int>a(n + 5),b(m + 5);
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<int>dp((1 << m) + 5,U);
    for (int k = 0; k < (1 << m); k++)
        for (int i = 1; i <= m; i++)
            if (k & (1 << (i - 1)))
                dp[k] &= b[i];
    vector<int>tmp(m + 5),ans;
    for (int i = 1; i <= n; i++)
    {
        fill(tmp.begin(),tmp.end(),inf);
        for (int k = 0; k < (1 << m); k++)
        {
            int j = __builtin_popcount(k);
            tmp[j] = min(tmp[j],a[i] & dp[k]);
        }
        for (int j = 0; j < m; j++)
            ans.push_back(tmp[j] - tmp[j + 1]);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for (int i = 0; i < k; i++)
        sum -= ans[i];
    cout << sum << '\n';
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