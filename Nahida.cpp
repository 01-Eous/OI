#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 507, M = 200007;
ll n, m, ans, a[N], b[N], c[N], cnt[N], mon[N], k[N][N], y[N][N];
vector<ll> to[N];
void dfs(int u, int fa)
{
    if (mon[fa] >= a[u])
    {
        mon[u] = mon[fa] + b[u];
        cnt[u] = cnt[fa] + 1;
    }
    else
    {
        mon[u] = mon[fa] - c[u];
        cnt[u] = cnt[fa];
    }
    for (auto v : to[u])
        if (v != fa)
            dfs(v, u);
}
bool OK(ll x)
{
    mon[0] = x;
    for (int i = 1; i <= n; ++i)
    {
        dfs(i, 0);
        for (int j = 1; j <= n; ++j)
            if (mon[j] < y[i][j] || cnt[j] < k[i][j])
                return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int u, v, i = 1; i < n; ++i)
    {
        cin >> u >> v;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    for (ll s, t, Y, K, i = 1; i <= m; ++i)
    {
        cin >> s >> t >> Y >> K;
        y[s][t] = max(y[s][t], Y);
        k[s][t] = max(k[s][t], K);
    }
    ll l = 0, r = 1e18, ans = 1e18;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (OK(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
