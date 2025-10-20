#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int idx,cnt;
bool vis[maxn];
int head[maxn],in[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx,in[v]++;
}
void topsort()
{
    stack<int,vector<int>> stk;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1)
            stk.push(i);
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (in[v] > 1)
            {
                in[v]--;
                if (in[v] == 1)
                    stk.push(v);
            }
        }
    }
}
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1,cnt++;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; in[v] == 2)
            dfs(v);
}
void solve()
{
    cin >> n >> k,idx = 0;
    memset(in,0,sizeof(int) * (n + 5));
    memset(vis,0,sizeof(bool) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1,x; i <= n; i++)
        cin >> x,adde(i,x),adde(x,i);
    topsort();
    for (int i = 1; i <= n; i++)
    {
        if (k == 1 && in[i] == 1)
            return (void)(cout << "NO\n");
        if (in[i] == 2 && !vis[i])
        {
            cnt = 0,dfs(i);
            if (cnt != k)
                return (void)(cout << "NO\n");
        }
    }
    cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}