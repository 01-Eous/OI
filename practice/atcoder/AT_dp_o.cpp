#include<bits/extc++.h>
#define add(x,y) x = (x + y) % mod;
using namespace std;
using ll = long long;
const int maxn = 1 << 21 | 5;
const ll mod = 1e9 + 7;
int n;
ll dp[maxn];
bool mp[25][25];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];
    dp[0] = 1;
    for (int s = 0; s < 1 << n; s++)
    {
        int i = __builtin_popcount(s);
        for (int j = 0; j < n; j++)
            if (!((s >> j) & 1) && mp[i][j])
                add(dp[s | (1 << j)],dp[s]);
    }
    cout << dp[(1 << n) - 1];
    return 0;
}