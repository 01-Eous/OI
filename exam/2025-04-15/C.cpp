#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5 + 5;
using pii = pair<int,int>;
int n,m;
int in[maxn],buc[maxn],ans[maxn];
vector<pii> g[maxn],que[maxn];
struct Klee{pii fir,sec;int from;}a[maxn];
void dfs1(int u,int fa)
{
    if (in[u] == 1)
        a[u] = {{0ll,u},{inf,n + 1},u};
    else
        a[u] = {{inf,n + 1},{inf,n + 1},0};
    for (auto [v,w] : g[u])
    {
        if (v == fa)
            continue;
        dfs1(v,u);
        pii tmp = a[v].fir;
        tmp.first += w;
        if (tmp < a[u].fir)
        {
            a[u].sec = a[u].fir;
            a[u].fir = tmp;
            a[u].from = v;
        }
        else if (tmp < a[u].sec)
            a[u].sec = tmp;
    }
    buc[a[u].fir.second]++;
}
void dfs2(int u,int fa)
{
    for (auto [s,id] : que[u])
        ans[id] = buc[s];
    for (auto [v,w] : g[u])
    {
        if (v == fa)
            continue;
        Klee tu = a[u],tv = a[v];
        buc[a[u].fir.second]--,buc[a[v].fir.second]--;
        if (a[u].from == v)
            a[u].fir = a[u].sec;
        pii tmp = a[u].fir;
        tmp.first += w;
        if (tmp < a[v].fir)
        {
            a[v].sec = a[v].fir;
            a[v].fir = tmp;
            a[v].from = u;
        }
        else if (tmp < a[v].sec)
            a[v].sec = tmp;
        buc[a[u].fir.second]++,buc[a[v].fir.second]++;
        dfs2(v,u);
        buc[a[u].fir.second]--,buc[a[v].fir.second]--;
        buc[tu.fir.second]++,buc[tv.fir.second]++;
        a[u] = tu,a[v] = tv;
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1,u,v,w; i < n; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        in[u]++,in[v]++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%lld",&m);
    for (int i = 1,s,t; i <= m; i++)
    {
        scanf("%lld%lld",&s,&t);
        que[t].push_back({s,i});
    }
    dfs1(1,0),dfs2(1,0);
    for (int i = 1; i <= m; i++)
        printf("%lld\n",ans[i]);
    return 0;
}