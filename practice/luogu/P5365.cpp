#include<bits/extc++.h>
#define int uint64_t
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
int a[150],c[150],dp[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1e6; j >= c[i]; j--)
            for (int k = 1; k <= a[i] && k * c[i] <= j; k++)
                dp[j] = max(dp[j],dp[j - k * c[i]] * k);
    int ans = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        if (dp[i] >= m)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}