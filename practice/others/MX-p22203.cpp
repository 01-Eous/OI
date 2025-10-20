#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,m,idx;
bool vis[maxn];
int head[maxn],dis[maxn];
vector<int> ans;
priority_queue<pii,vector<pii>,greater<>> q;
struct edge{int v,w,nxt;}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dij(int s)
{
    memset(dis,0x3f,sizeof(int) * (n + 5));
    dis[s] = 0;
    q.push({dis[s],s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push({dis[v],v});
            }
        }
    }
}
void dfs(int u)
{
    if (u == n)
    {
        for (auto i : ans)
            cout << i << ' ';
        cout << u,exit(0);
    }
    ans.push_back(u);
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; !vis[v] && dis[v] == dis[u] + e[i].w)
            dfs(v);
    ans.pop_back();
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u,v,w;
    while (m--)
    {
        cin >> u >> v >> w;
        adde(u,v,w),adde(v,u,w);
    }
    dij(1);
    memset(vis,0,sizeof(bool) * (n + 5));
    dfs(1);
    cout << "-1";
    return 0;
}