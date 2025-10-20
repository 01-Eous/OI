#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n,m,k,cnt;
int x[maxn],y[maxn];
bool vis[maxn],self[maxn];
map<pii,int> id;
vector<int> g[maxn],vec;
int toint(int x,int y)
{
    if (id.find({x,y}) != id.end())
        return id[{x,y}];
    return id[{x,y}] = ++cnt;
}
void adde(int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int u)
{
    vis[u] = 1;
    vec.push_back(u);
    for (auto v : g[u])
        if (!vis[v])
            dfs(v);
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= cnt; i++)
        vis[i] = self[i] = 0,g[i].clear();
    id.clear(),cnt = 0;
    for (int i = 0; i <= k; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= k; i++)
    {
        if (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) != 2)
            return cout << "0\n",void();
        if (x[i] == x[i - 1])
        {
            int tx = x[i],ty = (y[i - 1] + y[i]) >> 1;
            int tmp = toint(tx,ty);
            adde(tmp,tmp),self[tmp] = 1;
        }
        else if (y[i] == y[i - 1])
        {
            int tx = (x[i - 1] + x[i]) >> 1,ty = y[i];
            int tmp = toint(tx,ty);
            adde(tmp,tmp),self[tmp] = 1;
        }
        else
            adde(toint(x[i],y[i - 1]),toint(x[i - 1],y[i]));
    }
    int ans = 1;
    for (int i = 1; i <= cnt; i++)
    {
        if (vis[i])
            continue;
        vec.clear();
        dfs(i);

        int cnte = 0;
        bool fl = 0;
        for (auto u : vec)
        {
            cnte += g[u].size();
            fl |= self[u];
        }
        cnte >>= 1;

        if (cnte < vec.size())
            ans = ans * vec.size() % mod;
        else if (cnte == vec.size())
            ans = ans * (fl ? 1 : 2) % mod;
        else
        {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}