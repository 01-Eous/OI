#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
int n,idx;
bool vis[maxn];
int pr[maxn],phi[maxn];
void init(int n = 1e7)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
}
int binpow(int x,int y,int mod)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
int calc(int mod)
{
    if (mod == 1)
        return 0;
    return binpow(2,calc(phi[mod]) + phi[mod],mod);
}
void solve()
{
    cin >> n;
    cout << calc(n) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}