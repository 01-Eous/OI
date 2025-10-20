#include<bits/extc++.h>
using namespace std;
int n,m;
int dp[205][1005];
int bel[205],sc;
bool vis[205],rt[205];
int sumw[205],sumv[205];
int v[205],w[205],d[205];
int dfn[205],low[205],tim;
stack<int>st;
vector<int>g[205];
void dfs1(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    st.push(u);
    for (int v : g[u])
    {
        if (!dfn[v])
        {
            dfs1(v);
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
            lst = st.top();
            st.pop();
            bel[lst] = sc;
            vis[lst] = 0;
            sumv[sc] += v[lst];
            sumw[sc] += w[lst];
        }
    }
}
void dfs2(int u)
{
    for (int i = sumw[u]; i <= m; i++)
        dp[u][i] = sumv[u];
    for (int v : g[u])
    {
        dfs2(v);
        for (int i = m - sumw[u]; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[u][i + sumw[u]] = max(dp[u][i + sumw[u]],dp[u][i + sumw[u] - j] + dp[v][j]);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if (d[i])
            g[d[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i])
            continue;
        tim = 0;
        dfs1(i);
    }
    fill(g + 1,g + n + 1,vector<int>());
    fill(rt + 1,rt + sc + 1,1);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] && bel[i] != bel[d[i]])
        {
            g[bel[d[i]]].push_back(bel[i]);
            rt[bel[i]] = 0;
        }
    }
    for (int i = 1; i <= sc; i++)
        if (rt[i])
            g[0].push_back(i);
    dfs2(0);
    cout << dp[0][m];
    return 0;
}