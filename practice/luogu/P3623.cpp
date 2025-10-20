#include<bits/extc++.h>
using namespace std;
const int maxn = 2e4 + 5;
const int maxm = 1e5 + 5;
int n,m,k,cnt;
int fa[maxn];
struct edge{int u,v,w;}e[maxm];
vector<edge> ans;
bool cmp1(const edge &x,const edge &y){return x.w > y.w;}
bool cmp2(const edge &x,const edge &y){return x.w < y.w;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1,e + m + 1,cmp1);
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1; i <= m; i++)
    {
        auto [u,v,w] = e[i];
        u = find(u),v = find(v);
        if (u != v)
        {
            fa[u] = v;
            if (!w)
            {
                cnt++;
                e[i].w = -1;
            }
        }
    }
    if (cnt > k)
        return cout << "no solution",0;
    sort(e + 1,e + m + 1,cmp2);
    iota(fa + 1,fa + n + 1,1);
    cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        auto [u,v,w] = e[i];
        u = find(u),v = find(v);
        if (u == v)
            continue;
        if (e[i].w == 1 || cnt < k)
        {
            if (e[i].w < 1)
            {
                cnt++;
                e[i].w = 0;
            }
            ans.push_back(e[i]);
            fa[u] = v;
        }
    }
    if (cnt < k)
        return cout << "no solution",0;
    for (int i = 2; i <= n; i++)
        if (find(i) != find(1))
            return cout << "no solution",0;
    for (auto [u,v,w] : ans)
        cout << u << ' ' << v << ' ' << w << '\n';
    return 0;
}