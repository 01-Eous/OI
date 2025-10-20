#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,idx;
bool vis[maxn];
int id[maxn],cnt[maxn];
vector<int> g[maxn];
struct Klee
{
    int a[15];
    bool inf;
    Klee(int x = 0){memset(a,0,sizeof a);inf = 0;if (x) a[x] = 1;};
    void operator+=(const Klee &y)
    {
        if (inf || y.inf)
            return inf = 1,void();
        for (int i = 1; i <= idx; i++)
        {
            a[i] += y.a[i];
            if (a[i] > 1e15)
                return inf = 1,void();
        }
    }
    friend bool operator<=(const Klee &x,const Klee &y)
    {
        if (x.inf)
            return 0;    
        for (int i = 1; i <= idx; i++)
            if (x.a[i] > y.a[i])
                return 0;
        return 1;
    }
}c[maxn],tot;
Klee dfs(int u)
{
    if (id[u])
        return Klee(id[u]);
    if (vis[u])
        return c[u];
    vis[u] = 1;
    for (auto v : g[u])
        c[u] += dfs(v);
    return c[u];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,k; i <= m; i++)
    {
        cin >> k;
        if (k)
        {
            g[i].resize(k); 
            for (int j = 0; j < k; j++)
                cin >> g[i][j];
        }
        else
        {
            id[i] = ++idx;
            cin >> tot.a[idx];
        }
    }
    for (int i = 1; i <= n; i++)
        dfs(i);
    int ans = 0;
    for (int k = 0; k < (1 << n); k++)
    {
        Klee tmp;
        for (int i = 1; i <= n; i++)
            if (k & (1 << (i - 1)))
                tmp += c[i];
        if (tmp <= tot)
            ans = max(ans,(int)__popcount(k));
    }
    cout << ans;
    return 0;
}