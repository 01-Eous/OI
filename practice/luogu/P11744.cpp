#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,idx;
int by[505][505],bk[505][505];
int head[505],a[505],b[505],c[505],cnt[505],mon[505];
struct edge{int v,nxt;}e[1005];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    if (mon[fa] >= a[u])
    {
        mon[u] = mon[fa] + b[u];
        cnt[u] = cnt[fa] + 1;
    }
    else
    {
        mon[u] = mon[fa] - c[u];
        cnt[u] = cnt[fa];
    }
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa)
            dfs(v,u);
}
bool chk(int x)
{
    mon[0] = x;
    for (int i = 1; i <= n; i++)
    {
        dfs(i,0);
        for (int j = 1; j <= n; j++)
            if (mon[j] < by[i][j] || cnt[j] < bk[i][j])
                return 0;
    }
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    int s,t,y,k;
    while (m--)
    {
        cin >> s >> t >> y >> k;
        by[s][t] = max(by[s][t],y);
        bk[s][t] = max(bk[s][t],k);
    }
    int l = 0,r = 1e17,mid,res = 1e17;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << '\n';
    return 0;
}