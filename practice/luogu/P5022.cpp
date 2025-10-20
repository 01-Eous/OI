#include<bits/extc++.h>
using namespace std;
const int maxn = 5005;
int n,m,st;
int in[maxn],an[maxn];
bool vis[maxn],lp[maxn],flag;
vector<int>g[maxn];
void dfs1(int u,int fa)//on tree
{
    cout << u << " ";
    priority_queue<int,vector<int>,greater<int>>q;
    for (auto v : g[u])
        if (v != fa)
            q.push(v);
    while (!q.empty())
    {
        dfs1(q.top(),u);
        q.pop();
    }
}
void topsort()
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (in[v] > 1)
            {
                in[v]--;
                if (in[v] == 1)
                    q.push(v);
            }
        }
    }
}
void dfs2(int u)
{
    lp[u] = 1;
    for (auto v : g[u])
        if (in[v] == 2 && !lp[v])
            dfs2(v);
}
void dfs3(int u,int fa)
{
    if (flag)
        return;
    if (lp[u])
    {
        st = u;
        flag = 1;
        return;
    }
    for (auto v : g[u])
        if (v != fa)
            dfs3(v,u);
}
void dfs4(int u)
{
    cout << u << " ";
    vis[u] = 1;
    priority_queue<int,vector<int>,greater<int>>q;
    for (auto v : g[u])
        if (!vis[v])
            q.push(v);
    if (!lp[u] || (u != st && !flag))
    {
        while (!q.empty())
        {
            dfs4(q.top());
            q.pop();
        }
        return;
    }
    if (u == st)
    {
        while (!q.empty())
        {
            int v = q.top();
            q.pop();
            if (!lp[v])
                dfs4(v);
            else if (!flag)
            {
                an[v] = q.top();
                flag = 1;
                dfs4(v);
            }
            else
            {
                flag = 0;
                if (!vis[v])
                    dfs4(v);
            }
        }
    }
    else if (flag)
    {
        while (!q.empty())
        {
            int v = q.top();
            q.pop();
            if (!lp[v])
                dfs4(v);
            else
            {
                if (!q.empty())
                    an[v] = q.top();
                else
                    an[v] = an[u];
                if (v < an[v])
                    dfs4(v);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    if (m == n - 1)
    {
        dfs1(1,0);
        return 0;
    }
    topsort();
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 2)
        {
            dfs2(i);
            break;
        }
    }
    dfs3(1,0);
    flag = 0;
    dfs4(1);
    return 0;
}