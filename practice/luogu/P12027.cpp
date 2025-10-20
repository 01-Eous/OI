#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,m;
int c[maxn],ans[maxn];
int cnt[maxn],dis[maxn];
vector<int> g[maxn];
struct Nahida
{
    int id,val;
    bool type;// type = 0 表示是一条边，反之是一个查询
    friend bool operator<(const Nahida &x,const Nahida &y)
    {return x.val != y.val ? x.val > y.val : x.type > y.type;}
};
vector<Nahida> vec;
struct cmp{bool operator()(int x,int y) const {return dis[x] > dis[y];}};
set<int,cmp> st[15];
void dfs(int u)
{
    if (cnt[u] > 10)
        return;
    st[cnt[u]].erase(u);
    if (++cnt[u] <= 10)
        st[cnt[u]].insert(u);
    for (auto v : g[u])
        dfs(v);
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 2,p,d,e; i <= n; i++)
    {
        scanf("%lld%lld%lld",&p,&d,&e);
        dis[i] = dis[p] + e;
        g[p].push_back(i);
        vec.push_back({i,d,0});
    }
    scanf("%lld",&m);
    for (int i = 1,s; i <= m; i++)
    {
        scanf("%lld%lld",&s,c + i);
        vec.push_back({i,s,1});
    }
    sort(vec.begin(),vec.end());
    for (int i = 1; i <= n; i++)
        st[0].insert(i);
    for (auto [id,val,Tp] : vec)
    {
        if (Tp)
            for (int i = 0; i <= c[id]; i++)
                ans[id] = max(ans[id],dis[*st[i].begin()]);
        else
            dfs(id);
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n",ans[i]);
    return 0;
}