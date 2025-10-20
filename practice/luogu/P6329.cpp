#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define lowbit(x) ((x) & (-x))
using namespace std;
const int maxn = 1e5 + 5;
int n,m,a[maxn];
vector<int>g[maxn];
vector<int>tree[maxn][2];
void resize(int id,int siz){tree[id][0].resize(siz),tree[id][1].resize(siz);}
void upd(int i,int id,int op,int val)
{
    for (i++; i < tree[id][op].size(); i += lowbit(i))
        tree[id][op][i] += val;
}
int que(int i,int id,int op)
{
    int ret = 0;
    i = min(i + 1,(int)tree[id][op].size() - 1);
    for (; i; i -= lowbit(i))
        ret += tree[id][op][i];
    return ret;
}
namespace ctr
{
    int siz[maxn],son[maxn],dep[maxn],top[maxn],fa[maxn];
    void dfs1(int u,int pre)
    {
        fa[u] = pre,dep[u] = dep[pre] + 1,siz[u] = 1;
        for (auto v : g[u])
        {
            if (v == pre)
                continue;
            dfs1(v,u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
    void dfs2(int u,int tp)
    {
        top[u] = tp;
        if (!son[u])
            return ;
        dfs2(son[u],tp);
        for (auto v : g[u])
            if (v != fa[u] && v != son[u])
                dfs2(v,v);
    }
    int lca(int u,int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u,v);
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    int dis(int u,int v){return dep[u] + dep[v] - (dep[lca(u,v)] << 1);}
}
namespace algo
{
    bool vis[maxn];
    int ssiz,_min,rt;
    int siz[maxn],fa[maxn];
    int dfs1(int u,int fa)
    {
        int ret = 1;
        for (auto v : g[u])
            if (v != fa && !vis[v])
                ret += dfs1(v,u);
        return ret;
    }
    void dfs2(int u,int fa)
    {
        siz[u] = 1;
        int _max = 0;
        for (auto v : g[u])
        {
            if (v == fa || vis[v])
                continue;
            dfs2(v,u);
            siz[u] += siz[v];
            _max = max(_max,siz[v]);
        }
        _max = max(_max,ssiz - siz[u]);
        if (_max < _min)
        {
            _min = _max;
            rt = u;
        }
    }
    void dfs(int u)
    {
        resize(u,dfs1(u,0) + 2);
        vis[u] = 1;
        for (auto v : g[u])
        {
            if (vis[v])
                continue;
            _min = inf,rt = 0;
            ssiz = dfs1(v,0);
            dfs2(v,0);
            fa[rt] = u;
            dfs(rt);
        }
    }
}
void upd(int u,int val)
{
    for (int i = u; i; i = algo::fa[i])
        upd(ctr::dis(i,u),i,0,val);
    for (int i = u; algo::fa[i]; i = algo::fa[i])
        upd(ctr::dis(algo::fa[i],u),i,1,val);
}
int que(int u,int k)
{
    int ret = que(k,u,0);
    for (int i = u; algo::fa[i]; i = algo::fa[i])
    {
        int dis = ctr::dis(algo::fa[i],u);
        if (dis > k)
            continue;
        ret += que(k - dis,algo::fa[i],0) - que(k - dis,i,1);
    }
    return ret;
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v),g[v].push_back(u);
    }
    ctr::dfs1(1,0),ctr::dfs2(1,1);
    algo::_min = inf;
    algo::rt = 0;
    algo::ssiz = n;
    algo::dfs2(1,0);
    algo::dfs(algo::rt);
    for (int i = 1; i <= n; i++)
        upd(i,a[i]);
    int ans = 0,op,x,y;
    while (m--)
    {
        scanf("%d%d%d",&op,&x,&y);
        x ^= ans,y ^= ans;
        if (op == 0)
        {
            ans = que(x,y);
            printf("%d\n",ans);
        }
        else
        {
            upd(x,y - a[x]);
            a[x] = y;
        }
    }
    return 0;
}