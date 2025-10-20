#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,ans;
int a[maxn],c[maxn];
bool vis[maxn],lp[maxn];
int dfn[maxn],low[maxn],tim,sc;
int dp1[maxn][2],dp2[maxn][2];
stack<int>st;
vector<int>g[maxn],scc[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    st.push(u);
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        sc++;
        while (st.top() != u)
        {
            vis[st.top()] = 0;
            scc[sc].push_back(st.top());
            st.pop();
        }
        vis[st.top()] = 0;
        scc[sc].push_back(st.top());
        st.pop();
    }
}
void dfs(int u)
{
    dp1[u][0] = 0,dp1[u][1] = c[u];
    for (auto v : g[u])
    {
        if (lp[v])
            continue;
        dfs(v);
        dp1[u][0] += dp1[v][1];
        dp1[u][1] += min(dp1[v][0],dp1[v][1]);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= sc; i++)
    {
        vector<int> &p = scc[i];
        if (p.size() == 1 && a[p[0]] != p[0])
            continue;
        for (auto v : p)
            lp[v] = 1;
        for (auto v : p)
            dfs(v);
        dp2[p[0]][0] = dp1[p[0]][0];
        dp2[p[0]][1] = inf;
        for (int j = 1; j < p.size(); j++)
        {
            dp2[p[j]][0] = dp1[p[j]][0] + dp2[p[j - 1]][1];
            dp2[p[j]][1] = dp1[p[j]][1] + min(dp2[p[j - 1]][0],dp2[p[j - 1]][1]);
        }
        int tmp1 = dp2[p.back()][1];
        dp2[p[0]][0] = inf;
        dp2[p[0]][1] = dp1[p[0]][1];
        for (int j = 1; j < p.size(); j++)
        {
            dp2[p[j]][0] = dp1[p[j]][0] + dp2[p[j - 1]][1];
            dp2[p[j]][1] = dp1[p[j]][1] + min(dp2[p[j - 1]][0],dp2[p[j - 1]][1]);
        }
        int tmp2 = min(dp2[p.back()][0],dp2[p.back()][1]);
        ans += min(tmp1,tmp2);
    }
    cout << ans;
    return 0;
}