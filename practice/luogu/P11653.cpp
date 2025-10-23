#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e4 + 5;
int n,m,idx;
int s,t,res,ans;
pii a[maxn];
int head[maxn],deg[maxn],dp[maxn],fa[maxn];
vector<int> vec;
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x != y)
        fa[x] = y;
}
void dfs(int u,int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa)
            dfs(v,u);
    if (dp[u] > 0)
    {
        res++,merge(u,fa);
        dp[u]--,dp[fa]++;
        vec.push_back(u);
        vec.push_back(fa);
    }
    if (dp[u] < 0)
    {
        res++,merge(u,fa);
        dp[u]++,dp[fa]--;
        vec.push_back(u);
        vec.push_back(fa);
    }
}
void solve(int x)
{
    iota(fa + 1,fa + n + 1,1);
    memcpy(dp,deg,sizeof(int) * (n + 5));
    vec.clear(),res = 0,dfs(1,0);
    for (int i = 1; i <= n; i++)
        if (dp[i])
            return;
    for (int i = 1; i <= m; i++)
        merge(a[i].first,a[i].second);
    int tmp = find(a[1].first);
    for (auto i : vec)
        if (find(i) != tmp)
            return;
    ans = min(ans,res + x);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1,u,v; i <= n; i++)
    {
        cin >> u >> v;
        int fu = find(u),fv = find(v);
        if (fu != fv)
        {
            fa[fu] = fv;
            adde(u,v),adde(v,u);
        }
        else
            s = u,t = v;
    }
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        deg[u]++,deg[v]--;
        a[i] = {u,v};
    }
    ans = inf;
    deg[s]++,deg[t]--;
    solve(1);
    deg[s]--,deg[t]++;
    solve(0);
    deg[s]--,deg[t]++;
    solve(1);
    if (ans == inf)
        cout << "-1\n";
    else
        cout << m + ans << '\n';
    return 0;
}