#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
bool b[maxn];
int fa[maxn],siz[maxn],sum;
int head[maxn],idx,ans[maxn];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x == y)
        return;
    fa[x] = y;
    sum += siz[x] * siz[y];
    siz[y] += siz[x];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        b[i] = ch == '1';
    }
    for (int i = 1,u,v; i <= m; i++)
    {
        cin >> u >> v;
        adde(u,v);
        adde(v,u);
        if (b[u] && b[v])
            merge(u,v);
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = head[i]; j; j = e[j].nxt)
            if (int v = e[j].v; v > i || b[v])
                merge(i,v);
        int f = find(i);
        sum += siz[f]++;
        ans[i] = sum;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}