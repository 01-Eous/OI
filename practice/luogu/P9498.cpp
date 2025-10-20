#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e6 + 5;
int n,idx,sum;
pii dep[maxn];
int head[maxn];
bool ans[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    dep[u] = {dep[fa].first + 1,u};
    sum += dep[u].first;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa)
            dfs(v,u);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    if (sum & 1)
        return cout << "-1",0;
    sum >>= 1;
    sort(dep + 1,dep + n + 1,greater<>());
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp + dep[i].first <= sum)
        {
            ans[dep[i].second] = 1;
            tmp += dep[i].first;
        }
    }
    if (tmp != sum)
        return cout << "-1",0;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}