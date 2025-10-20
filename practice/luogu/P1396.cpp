#include<bits/extc++.h>
using namespace std;
int n,m,s,t;
int fa[10005];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
struct edge{int u,v,w;};
vector<edge>e;
bool operator<(const edge &x,const edge &y){return x.w < y.w;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1,u,v,w; i <= m; i++)
    {
        cin >> u >> v >> w;
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end());
    for (auto [u,v,w] : e)
    {
        u = find(u),v = find(v);
        if (u != v)
            fa[u] = v;
        if (find(s) == find(t))
        {
            cout << w;
            return 0;
        }
    }
    return 0;
}