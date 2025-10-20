#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn],dp[maxn],_max[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i >= a[i])
            dp[i] = _max[i - a[i]] + 1;
        _max[i] = max(_max[i - 1],dp[i]);
    }
    cout << dp[n];
    return 0;
}