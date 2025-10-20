#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 2.6e7 + 5;
int n,mod,idx;
bool vis[maxn];
int pr[maxn],dp[maxn];
inline void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
            if (vis[i * pr[j]] = 1; i % pr[j] == 0)
                break;
    }
}
signed main()
{
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    init(),dp[0] = 1;
    for (int i = 1; i <= idx; i++)
    {
        for (int j = n; j >= pr[i]; j--)
        {
            int tmp = pr[i];
            while (tmp <= j)
            {
                dp[j] = (dp[j] + dp[j - tmp] * tmp) % mod;
                tmp *= pr[i];
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % mod;
    cout << ans;
    return 0;
}