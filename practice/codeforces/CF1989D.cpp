#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,m;
int a[maxn],b[maxn],c[maxn],f[maxn],dp[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f,0x3f,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        f[a[i]] = min(f[a[i]],a[i] - b[i]);
    }
    for (int i = 1; i <= 1e6; i++)
        f[i] = min(f[i],f[i - 1]);
    for (int i = 1; i <= 1e6; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= f[i])
            dp[i] = max(dp[i],dp[i - f[i]] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
        if (c[i] > 1e6)
        {
            int tmp = (c[i] - (int)1e6) / f[(int)1e6] + 1;
            ans += tmp;
            c[i] -= tmp * f[(int)1e6];
        }
        ans += dp[c[i]];
    }
    cout << (ans << 1);
    return 0;
}