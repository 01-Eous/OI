#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,m;
bool vis[maxn];
int cnt[maxn],len[maxn];
vector<int> g[maxn];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = cnt[u] = 1;
    for (auto v : g[u])
    {
        dfs(v);
        cnt[u] = (cnt[u] + cnt[v]) % mod;
        len[u] = (len[u] + len[v] + cnt[v]) % mod;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u,v;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    int sumc = 0,suml = 0;
    for (int i = 1; i <= n; i++)
    {
        sumc = (sumc + cnt[i]) % mod;
        suml = (suml + len[i]) % mod;
    }
    cout << suml * binpow(sumc,mod - 2) % mod;
    return 0;
}