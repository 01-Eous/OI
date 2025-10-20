#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1.5e5 + 5;
using iii = array<int,3>;
using pii = pair<int,int>;
int n;
iii sum;
bool fl;
int col[maxn];
bool vis[maxn];
pii dp[maxn];
stack<int> stk;
vector<iii> pend,ans;
vector<int> g[maxn],path,vec;
pii operator+(pii x,int y)
{
    x.first += y;
    return x;
}
void dfs1(int u,int fa)
{
    stk.push(u);
    col[u] = 1;
    for (auto v : g[u])
        if (v != fa && !vis[v])
            dfs1(v,u);
}
void dfs2(int u,int fa)
{
    dp[u] = {1,u};
    sum = max(sum,{1,u,u});
    for (auto v : g[u])
    {
        if (v == fa || vis[v])
            continue;
        dfs2(v,u);
        iii tmp = {dp[u].first + dp[v].first,dp[u].second,dp[v].second};
        if (tmp[1] < tmp[2])
            swap(tmp[1],tmp[2]);
        sum = max(sum,tmp);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}
void dfs3(int u,int ed,int fa)
{
    vec.push_back(u);
    if (u == ed)
        fl = 1,path = vec;
    if (fl)
        return;
    for (auto v : g[u])
        if (v != fa && !vis[v])
            dfs3(v,ed,u);
    vec.pop_back();
}
void solve()
{
    scanf("%lld",&n);
    memset(col,0,sizeof(int) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans.clear();
    while (1)
    {
        pend.clear();
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] || col[i])
                continue;
            sum = {0,0,0};
            dfs1(i,0),dfs2(i,0);
            pend.push_back(sum);
        }
        if (pend.empty())
            break;
        for (auto i : pend)
        {
            ans.push_back(i);
            vec.clear(),path.clear();
            fl = 0;
            dfs3(i[1],i[2],0);
            for (auto u : path)
                vis[u] = 1;
        }
        while (!stk.empty())
        {
            col[stk.top()] = 0;
            stk.pop();
        }
    }
    sort(ans.begin(),ans.end(),greater<>());
    for (auto [x,y,z] : ans)
        printf("%lld %lld %lld ",x,y,z);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}