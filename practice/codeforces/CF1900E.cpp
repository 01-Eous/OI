#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,sc,tim;
bool vis[maxn];
int u[maxn],v[maxn],in[maxn];
int a[maxn],dfn[maxn],low[maxn];
int bel[maxn],siz[maxn],val[maxn];
stack<int> stk;
vector<int> g1[maxn],g2[maxn];
struct Klee
{
    int dis,val;
    friend bool operator<(const Klee &x,const Klee &y)
    {return x.dis != y.dis ? x.dis < y.dis : x.val > y.val;}
    friend Klee operator+(const Klee &x,const Klee &y)
    {return Klee{x.dis + y.dis,x.val + y.val};}
}dp[maxn];
void clear()
{
    fill(in + 1,in + n + 1,0);
    fill(vis + 1,vis + n + 1,0);
    fill(dfn + 1,dfn + n + 1,0);
    fill(low + 1,low + n + 1,0);
    fill(bel + 1,bel + n + 1,0);
    fill(siz + 1,siz + n + 1,0);
    fill(val + 1,val + n + 1,0);
    fill(dp + 1,dp + n + 1,Klee{0,0});
    for (int i = 1; i <= n; i++)
        g1[i].clear(),g2[i].clear();
    sc = tim = 0;
}
void dfs(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    stk.push(u);
    for (auto v : g1[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        sc++;
        int lst = 0;
        while (lst != u)
        {
            lst = stk.top();
            bel[lst] = sc;
            siz[sc]++;
            val[sc] += a[lst];
            vis[lst] = 0;
            stk.pop();
        }
    }
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= sc; i++)
    {
        if (!in[i])
        {
            dp[i] = {siz[i],val[i]};
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g2[u])
        {
            dp[v] = max(dp[v],dp[u] + Klee{siz[v],val[v]});
            if (!--in[v])
                q.push(v);
        }
    }
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    clear();
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",u + i,v + i);
        g1[u[i]].push_back(v[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= m; i++)
    {
        if (bel[u[i]] != bel[v[i]])
        {
            g2[bel[u[i]]].push_back(bel[v[i]]);
            in[bel[v[i]]]++;
        }
    }
    topsort();
    Klee ans = {0,0};
    for (int i = 1; i <= sc; i++)
        ans = max(ans,dp[i]);
    printf("%lld %lld\n",ans.dis,ans.val);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}