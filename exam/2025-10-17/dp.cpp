#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ld = double;
int n,l,r;
int b[5005];
ld a[5005],dp[8005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        a[i] = log10(a[i]);
    }
    for (int i = 1; i <= r; i++)
        dp[i] = -inf;
    for (int i = 1; i <= n; i++)
        for (int j = r; j >= b[i]; j--)
            dp[j] = max(dp[j],dp[j - b[i]] + a[i]);
    ld ans = 0;
    for (int i = l; i <= r; i++)
        ans = max(ans,pow(10,dp[i] / i));
    cout << fixed << setprecision(8) << ans << '\n';
    return 0;
}