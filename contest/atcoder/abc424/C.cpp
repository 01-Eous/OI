#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,idx;
bool vis[maxn];
int a[maxn],b[maxn],head[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
        dfs(e[i].v);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] || b[i])
        {
            adde(a[i],i);
            adde(b[i],i);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!a[i] && !b[i])
            dfs(i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += vis[i];
    cout << ans;
    return 0;
}