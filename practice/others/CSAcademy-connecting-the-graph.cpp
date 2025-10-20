#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],p[maxn],fa[maxn];
struct edge
{
    int u,v,w;
    friend bool operator<(const edge &x,const edge &y){return x.w < y.w;}
};
vector<edge> e;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
bool cmp(int x,int y){return a[x] < a[y];}
signed main()
{
    scanf("%lld%lld",&n,&m);
    iota(p + 1,p + n + 1,1);
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(p + 1,p + n + 1,cmp);
    for (int i = 1; i < n; i++)
        e.push_back({p[i],p[i + 1],sq(a[p[i + 1]] - a[p[i]])});
    int u,v;
    while (m--)
    {
        scanf("%lld%lld",&u,&v);
        e.push_back({u,v,0});
    }
    sort(e.begin(),e.end());
    int ans = 0;
    for (auto [u,v,w] : e)
    {
        u = find(u),v = find(v);
        if (u != v)
        {
            ans += w;
            fa[u] = v;
        }
    }
    printf("%lld",ans);
    return 0;
}
