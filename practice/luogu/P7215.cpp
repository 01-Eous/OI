#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,k,tot,ans = inf;
int col[maxn],head[maxn],idx;
bool vis[maxn],vis1[maxn],vis2[maxn];
int fa[maxn],siz[maxn],wei[maxn],ssiz,rt;
vector<int>b[maxn];
stack<int>st;
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int pre)
{
    siz[u] = 1,wei[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == pre || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int pre)
{
    vis1[u] = 1;
    st.push(u);
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != pre && !vis[v])
            dfs2(v,u);
}
void dfs3(int u,int pre)
{
    fa[u] = pre;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != pre && !vis[v])
            dfs3(v,u);
}
bool push(queue<int> &q,vector<int> &v)
{
    for (auto i : v)
    {
        if (!vis1[i])
            return 1;
        q.push(i);
    }
    tot++;
    return 0;
}
void calc(int u)
{
    tot = 0;
    queue<int> q;
    vis2[col[u]] = 1;
    if (push(q,b[col[u]]))
        return;
    dfs3(u,u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (!vis2[col[fa[v]]])
        {
            vis2[col[fa[v]]] = 1;
            if (push(q,b[col[fa[v]]]))
                return;
        }
    }
    ans = min(ans,tot);
}
void dfs(int u)
{
    vis[u] = 1;
    dfs2(u,0);
    calc(u);
    while (!st.empty())
    {
        vis1[st.top()] = vis2[col[st.top()]] = 0;
        st.pop();
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v]) 
            continue;
        wei[rt = 0] = inf;
        ssiz = siz[v];
        dfs1(v,u);
        dfs(rt);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        b[col[i]].push_back(i);
    }
    wei[rt = 0] = inf;
    ssiz = n;
    dfs1(1,0);
    dfs(rt);
    cout << ans - 1;
    return 0;
}