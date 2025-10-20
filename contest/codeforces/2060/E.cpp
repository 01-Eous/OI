#include<bits/extc++.h>
using namespace std;
int n,m1,m2;
int find(vector<int>&fa,int x){return fa[x] == x ? x : fa[x] = find(fa,fa[x]);}
void un(vector<int>&fa,int u,int v)
{
    u = find(fa,u),v = find(fa,v);
    if (u != v)
        fa[u] = v;
}
void solve()
{
    scanf("%d%d%d",&n,&m1,&m2);
    vector<pair<int,int>>g1(m1),g2(m2);
    for (auto &[u,v] : g1)
        scanf("%d%d",&u,&v);
    vector<int>dsu1(n + 5),dsu2(n + 5);
    iota(dsu1.begin() + 1,dsu1.begin() + n + 1,1);
    iota(dsu2.begin() + 1,dsu2.begin() + n + 1,1);
    for (auto &[u,v] : g2)
    {
        scanf("%d%d",&u,&v);
        un(dsu1,u,v);
    }
    int ans = 0;
    for (auto [u,v] : g1)
    {
        if (find(dsu1,u) != find(dsu1,v))
            ans++;
        else
            un(dsu2,u,v);
    }
    for (auto [u,v] : g2)
    {
        if (find(dsu2,u) != find(dsu2,v))
        {
            ans++;
            un(dsu2,u,v);
        }
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}