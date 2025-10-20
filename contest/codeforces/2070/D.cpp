#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n;
int p[maxn],dep[maxn],f[maxn];
vector<int>g[maxn],b[maxn];
void dfs(int u)
{
    b[dep[u]].push_back(u);
    for (auto v : g[u])
    {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        g[i].clear(),b[i].clear();
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld",p + i);
        g[p[i]].push_back(i);
    }
    dfs(1);
    int sum = 0;
    for (auto v : g[1])
    {
        f[v] = 1;
        sum++;
    }
    int ans = sum + 1;
    for (int i = 2; i < n; i++)
    {
        int tmp = 0;
        for (auto v : b[i])
        {
            f[v] = (sum - f[p[v]] + mod) % mod;
            tmp = (tmp + f[v]) % mod;
        }
        sum = tmp;
        ans = (ans + tmp) % mod;
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}