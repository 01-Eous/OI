#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e4 + 5;
int n,m,idx,tim,cnt;
bool vis[maxn];
int a[maxn],head[maxn],bel[maxn];
int dfn[maxn],low[maxn],val[maxn];
struct{int v,nxt;}e[maxn * 5];
stack<int,vector<int>> stk;
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1,stk.push(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] >= dfn[u])
    {
        val[++cnt] = inf;
        int lst = 0;
        while (lst != u)
        {
            lst = stk.top();
            stk.pop();
            vis[lst] = 0;
            bel[lst] = cnt;
            val[cnt] = min(val[cnt],a[lst]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    while (m--)
    {
        int u,v;
        cin >> u >> v;
        adde(u,v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        ans += val[i];
    cout << ans << " 1";
    return 0;
}