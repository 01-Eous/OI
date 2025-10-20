#include<bits/extc++.h>
using namespace std;
using ld = long double;
int n,t,r;
ld p,f[2005],dp[2005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t >> r >> p;
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] + 1 + p * r) / (1 - p); 
    for (int i = 1; i <= n; i++)
    {
        dp[i] = f[i];
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i],dp[j] + t + f[i - j]);
    }
    cout << fixed << setprecision(8) << dp[n] + t;
    return 0;
}